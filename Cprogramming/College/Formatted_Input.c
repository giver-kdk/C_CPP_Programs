#include <stdio.h>
void main()
{
    int a;
    char ch;
    printf("Enter a number");
    scanf("%d", &a);
    printf("Enter a character");
    scanf(" %c", &ch);                                      //here note the spacebefore %c 
    printf("\nNumber: %d\tCharcater: %c", a, ch);
}