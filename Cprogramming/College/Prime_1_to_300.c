#include <stdio.h>

int main()
{
    int n=1, i, j;

    printf("Prime numbers between 1 and 200: ");                     
    while(n<=200)
    {     
        i=2;                     //Inside loop to reset i=2 for next even check
        while(i<=n-1)     
        {
            if(n%i==0)                    //Exits the loop if 'i' is even.
            {
                break;
            }
            i++;                      //Increments 'i'.
        }     
        if(i==n)          //If 'i' is not divisible by any number from 2 to num-1, then prints 'i'.
        {
            printf("%d\n", i);      
        }    
        n++;                  //Increments 'num' for next loop.
    }
}