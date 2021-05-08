#include <stdio.h>
#include <conio.h>
void main()
{
    int a, b, add, subtract, multiply, divide, remainder;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    add=a+b;                            //Addition Operator
    subtract=a-b;                       //Subtraction Operator
    multiply=a*b;                       //Multiplication Operator
    divide=a/b;                         //Division Operator
    remainder=a%b;                       //Modulo Division Operator / Remainder Operator
    printf("The addition is: %d", add);
    printf("\nThe subtraction is: %d", subtract);
    printf("\nThe multiplication is: %d", multiply);
    printf("\nThe division is: %d", divide);
    printf("\nThe reminder is: %d", remainder);
}