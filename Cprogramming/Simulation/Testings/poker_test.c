#include <stdio.h>
#include <math.h>
#define SIZE 100

int main() {
    int Oi[SIZE], digit, n, N, i;
	double Ei[SIZE], Oi_Ei[SIZE], chiSquare = 0;
	double alpha, tab;
	// Probability Order: 3 like digits, 3 different digits, 1 pair
	double threeDigitP[] = {0.01, 0.72, 0.27};
	// Probability Order: 4 like digits, 3 like digits, 4 different digits, 1 pair, 2 pairs
	double fourDigitP[] = {0.001, 0.036, 0.504, 0.432, 0.027};
	// Let's use 1000
	printf("Enter total number of sequence: ");
	scanf("%d", &N);
	// 3 or 4 is allowed. Let's use 3
	printf("Enter the number of variabels(3 or 4): ");
	scanf("%d", &digit);
	if(digit == 3 || digit == 4)
	{
		if(digit == 3) n = 3;
		else n = 5;

		Ei[i] = 0;
		// Use: 31, 680, 289
		// Order same as array "threeDigitP[]"
		for(i = 0; i < n; i++){
			printf("Enter Observed Frequency Oi[%d]: ", i + 1);
			scanf("%d", &Oi[i]);
		}
		for(i = 0; i < n; i++){
			if(digit == 3) Ei[i] = N * threeDigitP[i];
			else Ei[i] = N * fourDigitP[i];
			// (Oi = Ei)^2 / Ei
			Oi_Ei[i] = pow((Oi[i] - Ei[i]), 2) / Ei[i];
			chiSquare += Oi_Ei[i];
		}
		// Use alpha = 0.05
		printf("Enter value of alpha: ");
		scanf("%lf", &alpha);
		// Use tab = 5.99
		printf("Enter the tabulated value: ");
		scanf("%lf", &tab);
		printf("Calculated value: %lf", chiSquare);
		if(chiSquare <= tab){
			printf("For aplha = %lf, Hypothesis is accepted.", alpha);
			printf("\nHence the given data are independant.");
		}
		else{
			printf("For aplha = %lf, Hypothesis is rejected.", alpha);
			printf("\nHence the given data are dependant.");
		}
	}
	else printf("\nInvalid digit number.");
	printf("\nName: Giver Khadka\tRoll no.: 05");
    return 0;
}
