#include <stdio.h>

/*Fibonacce Series function with no return type and with argument.*/
void print_fibonacce(int num);

void main()
{
    int number;
    printf("Enter a number for Fibonacce Series: ");
    scanf("%d", &number);
    print_fibonacce(number);
}
void print_fibonacce(int num)
{
    int i, prev=1, next=1, fib1;
    printf("%d\t", prev);
    for(i=1; i<=num; i++)
    {
        fib1=prev+next;
        prev= next;
        next= fib1;
        printf("%d\t", prev);
    }
}