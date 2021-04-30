#include <stdio.h>
void main()
{
    int a, b;
    printf("Enter the value of a; ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    if(a>b)
        printf("a is the greatest");
    else
        printf("b is the greatest");
}