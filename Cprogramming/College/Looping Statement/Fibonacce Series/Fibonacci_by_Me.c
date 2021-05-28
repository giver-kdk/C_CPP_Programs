#include <stdio.h>
#include <conio.h>

int main()
{
    int i=1, a=1, b=1, c, n;
    printf("Enter any number: ");
    scanf("%d", &n);

    do{
        c= a+b;
        printf("%d\t", a);
        a=b;
        b=c;
        
        i=i+1;

    }while(i<=n);
}