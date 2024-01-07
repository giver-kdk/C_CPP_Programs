#include <stdio.h>
#include <math.h>

int main() {
    int n, i, k, m, M;
	double alpha, rho = 0, sigma, Zcalc, Ztab;
	double data[] = {
	0.12, 0.01, 0.23, 0.28, 0.99, 0.31, 0.64, 0.28, 0.83, 0.93,
	0.99, 0.15, 0.33, 0.35, 0.91, 0.41, 0.60, 0.27, 0.75, 0.88, 
	0.68, 0.49, 0.05, 0.43, 0.95, 0.58, 0.19, 0.36, 0.69, 0.87}; 
	n = sizeof(data) / sizeof(double);
	// Use i  = 3
	printf("Enter starting position, i: ");
	scanf("%d", &i);
	// Use m  = 5
	printf("Enter difference lag value, m: ");
	scanf("%d", &m);

	M = (n - i) / m - 1;
	sigma = (sqrt(13 * M + 7)) / (12 * (M + 1));

	for(k = 0; k <= M; k++){
		rho += data[(i + k*m) - 1] * data[(i + (k + 1)*m) - 1];
	}	
	rho = (rho / 5) - 0.25;
	Zcalc = fabs(rho / sigma);
	// Use alpha = 0.05
	printf("Enter value of alpha: ");
	scanf("%lf", &alpha);
	// Use tab = 1.96
	printf("Enter the tabulated value: ");
	scanf("%lf", &Ztab);
	// Output
	printf("\nValue of M: %d", M);
	printf("\nSigma: %lf", sigma);
	printf("\nRho: %lf", rho);
	printf("\nCalculated value of |Zcalc|: %lf", Zcalc);
	if(Zcalc <= Ztab){
		printf("\nFor aplha = %lf, Hypothesis is accepted.", alpha/2);
		printf("\nHence the given data are independant.");
	}
	else{
		printf("\nFor aplha = %lf, Hypothesis is rejected.", alpha/2);
		printf("\nHence the given data are dependant.");
	}
    return 0;
}
