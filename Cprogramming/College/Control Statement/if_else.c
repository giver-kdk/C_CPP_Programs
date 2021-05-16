#include <stdio.h>
#include <conio.h>

void main()
{
    int num;
    printf("Enter any number: ");
    scanf("%d", &num);
    if(num%2==0)
    {
        printf("Entered number is even");

    }
    else
    {
        printf("Entered number is odd");
    }
    printf("\nGoodBye");
}