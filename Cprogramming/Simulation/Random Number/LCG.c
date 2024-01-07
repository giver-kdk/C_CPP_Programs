// Implement LCG with menu options
#include <stdio.h>

int main()
{
	int a, c, m, x0, x1;
	char ch;
	float r;
	while (ch != 'n' && ch != 'N')
	{
		printf("Enter value of x0: ");
		scanf("%d", &x0);
		printf("Enter value of a: ");
		scanf("%d", &a);
		printf("Enter value of c: ");
		scanf("%d", &c);
		printf("Enter value of m: ");
		scanf("%d", &m);
		printf("\n1) Additive LCG\n2) Multiplicative LCG\n3) Mixed LCG");
		printf("\nEnter your choice: ");
		scanf(" %c", &ch);
		switch (ch)
		{
			case '1':
					a = 1;
					break;
			case '2':
					c = 0;
					break;
			case '3':
					break;
			default:
					printf("Invalid Choice");
		}
		x1 = x0;
		for (int i = 0; i < 20; i++)
		{
			x1 = (a * x1 + c) % m;
			r = x1 / m;
			printf("%d\t", x1);
		}
		printf("\nContinue? (Y/N): ");
		scanf(" %c", &ch);
	}

}
