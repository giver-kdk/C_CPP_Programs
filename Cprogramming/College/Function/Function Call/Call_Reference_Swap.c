#include <stdio.h>

/*This program swaps the value of two variables.*/
void swap(int *x, int *y);              //Declaring fx with pointer argumnets.

void main()
{
    int a, b;
    a=50;
    b=60;
    printf("Before the swap, value of a= %d", a);
    printf("\nBefore the swap, value of b= %d", b);
    swap(&a, &b);                                       //Adress of 'a' and 'b' sent as argument.
    printf("\nAfter the swap, value of a= %d", a);          //Values of a and b are also swaped
    printf("\nAfter the swap, value of b= %d", b);
}
void swap(int *x, int *y)
{
    int temp;
    temp= *x;
    *x= *y;
    *y= temp;
    printf("\nValue of x= %d", *x);          //Value of x and y is swaped
    printf("\nValue of y= %d", *y);
}