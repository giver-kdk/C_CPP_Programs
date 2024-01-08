#include <stdio.h>
#include <math.h>
#define SIZE 100

int main() {
    int Oi[SIZE], Oi_sum = 0, n, i;
	double Ei[SIZE], Oi_Ei[SIZE], unitEi, chiSquare = 0;
	double alpha, tab;
	// Use: n = 10
	printf("Enter the number of intervals: ");
	scanf("%d", &n);

	Ei[i] = 0;
	// Use: 7, 9, 8, 9, 14, 7, 10, 15, 9, 12
	for(i = 0; i < n; i++){
		printf("Enter Observed Frequency Oi[%d]: ", i + 1);
		scanf("%d", &Oi[i]);
		Oi_sum += Oi[i];
	}
	unitEi = Oi_sum / n;
	for(i = 0; i < n; i++){
		Ei[i] = unitEi;
		// (Oi = Ei)^2 / Ei
		Oi_Ei[i] = pow((Oi[i] - Ei[i]), 2) / Ei[i];
		chiSquare += Oi_Ei[i];
	}
	// Use alpha = 0.05
	printf("Enter value of alpha: ");
	scanf("%lf", &alpha);
	// Use tab = 16.9
	printf("Enter the tabulated value: ");
	scanf("%lf", &tab);
	if(chiSquare <= tab){
		printf("For aplha = %lf, Hypothesis is accepted.", alpha);
		printf("Hence the given data are uniform.");
	}
	else{
		printf("For aplha = %lf, Hypothesis is rejected.", alpha);
		printf("Hence the given data are not uniform.");
	}
	printf("\nName: Giver Khadka\tRoll no.: 05");
    return 0;
}
