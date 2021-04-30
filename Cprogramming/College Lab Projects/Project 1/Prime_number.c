#include <stdio.h>
#include <conio.h>
void main()
{
	int n, i=1, count=0;
	printf("Enter any number: ");
	scanf("%d",&n);
	for (i=1; i<=n; i=i+1)
	{
		if(n%i==0)
		count= count+1;	
	}
	if(count==2)
		printf("The number is a prime number");
	else
		printf("The number is not a prime number");
 	
}
