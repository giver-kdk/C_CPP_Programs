#include <stdio.h>
void main()
{
	int a;
	int b;
	int c;
	printf("Enter the first number a:");
	scanf("%d",&a);
	printf("Enter the second number b:");
	scanf("%d",&b);
	printf("Enter the third number c:");
	scanf("%d",&c);
	if(a>b & b>c)
	printf("a is the greatest number");
	else if(b>a & a>c)
	printf("b is the greatest number");
	else
	printf("c is the greatest number");
}
