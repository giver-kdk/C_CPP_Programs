#include <stdio.h>

/*Fibonacce Series function with return type and with no argument.*/
int print_fibonacce();

void main()
{
    int previous;
    previous= print_fibonacce();
    printf("%d", print_fibonacce());
 
}
int print_fibonacce()
{
    int i, num, prev=1, next=1, fib1;
    printf("Enter a number for Fibonacce Series: ");
    scanf("%d", &num);
    printf("%d\t", prev);
    for(i=1; i<=num; i++)
    {
        fib1=prev+next;
        prev= next;
        next= fib1;
        return(prev)                
    }
}       /* INCOMPLETE */