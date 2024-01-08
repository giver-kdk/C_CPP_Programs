#include <stdio.h>
#define LEVEL 20
#define TIME 100
#define ERROR 0.01

struct Customer{
	int AT;				// Arrival Time
	int ST;				// Service Time
	int SB;				// Service Begin
	int SE;				// Service End
};
struct SystemQueue{
	int maxLevel;
	int matrix[LEVEL][TIME];
} Qsys;
int main()
{
	int n, i, j, k, isBusy, Ti[LEVEL] = {0}, Tqi[LEVEL] = {0}, Wi[LEVEL] = {0}, Wqi[LEVEL] = {0};
	float L = 0, Lq = 0, W = 0, Wq = 0, rho, lamda;
	// Use n = 5
	printf("Enter the number of customers: ");
	scanf("%d", &n);
	struct Customer C[n];
	C[0].AT = 0;
	// Use 4, 0, 2, 3
	for(i = 1; i < n; i++){
		printf("Enter Inter Arrival Time for C%d: ", i+1);
		scanf("%d", &C[i].AT);
		C[i].AT += C[i - 1].AT;
	}
	// Use 5, 3, 4, 2, 3
	for(i = 0; i < n; i++){
		printf("Enter Service Time for C%d: ", i+1);
		scanf("%d", &C[i].ST);
		if(i == 0){
			C[i].SB = C[i].AT;
			C[i].SE = C[i].ST;
		}
		else{
			isBusy = C[i].AT <= C[i - 1].SE;
			if(isBusy) C[i].SB = C[i - 1].SE;
			else C[i].SB = C[i].AT;
			C[i].SE = C[i].SB + C[i].ST;
		}
		// Calculate Wi
		Wi[i] = C[i].SE - C[i].AT;
	}
	Qsys.maxLevel = 0;
	Qsys.matrix[0][0] = 0;
	for(i = 0; i < n; i++)
	{
		for(j = C[i].AT, k = 0; j < C[i].SE; j++)
		{
			while(Qsys.matrix[k][j] != 0){
				k++;
				if(k > Qsys.maxLevel) Qsys.maxLevel = k;
			}
			Qsys.matrix[k][j] = i + 1;
			// Calculate Wqi
			if(k > 0) Wqi[i]++;
			k = 0;
		}
	}
	// Here, Calculation and Output are independant
	printf("\nQueuing System Representation: \n");
	for(i = Qsys.maxLevel; i >= 0; i--)
	{
		for(j = 0; j < C[n - 1].SE; j++)
		{
			// Print Blocks
			if(Qsys.matrix[i][j] == 0) printf("|  ");
			else printf("|C%d", Qsys.matrix[i][j]);
			if(j == C[n - 1].SE - 1) printf("|");
			// Calculate Ti
			if(i == 0 && Qsys.matrix[i][j] == 0) Ti[i]++;
			else if(Qsys.matrix[i][j] != 0){
				if(Qsys.matrix[i + 1][j] == 0) Ti[i + 1]++;
			}
		}
		printf("\n");
	}
	// Calcuate L and Lq
	Tqi[0] = Ti[0] + Ti[1];
	for(i = 0; i <= Qsys.maxLevel + 1; i++){
		L += i*Ti[i];
		if(i < Qsys.maxLevel + 1){
			if(i > 0) Tqi[i] = Ti[i + 1];
		 	Lq += i*Tqi[i];
		}
	}
	L /= C[n - 1].SE;
	Lq /= C[n - 1].SE;
	printf("\nTime Average Number in System, L = %.2f", L);
	printf("\nTime Average Number in Queue, Lq = %.2f", Lq);
	// Calcuate W and Wq
	for(i = 0; i < n + 1; i++){
		W += Wi[i];
		Wq += Wqi[i];
	}
	W /= n;
	Wq /= n;
	printf("\nAverage Time spent in System, W = %.2f", W);
	printf("\nAverage Time spent in Queue, Wq = %.2f", Wq);
	// Calculate Server Utilization
	rho = (C[n - 1].SE - Ti[0]) / C[n - 1].SE;
	printf("\nSever Utilization = %.2f", rho);
	// Proving Conservation Equation
	lamda = ((float) n / (float) C[n - 1].SE);
	printf("\nL = %.2f and Lamda x W = %.2f", L, lamda*W);
	if(L - lamda * W <= ERROR) printf("\nHence, conservation equation was satisfied.");
	else printf("\nHence, conservation equation was not satisfied.");
	printf("\nName: Giver Khadka\tRoll no.: 05");
	return 0;
}