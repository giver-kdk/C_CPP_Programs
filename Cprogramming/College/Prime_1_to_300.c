#include <stdio.h>

int main()
{
    int num=1, i, j;

    printf("The prime number between 1 to 300 are: \n");                     
    while(num<=300)
    {     
        i=2;
        while(i<=num-1)     
        {
            if(num%i==0)                    //Exits the loop if 'i' is even.
            {
                break;
            }
            i++;                      //Increments 'i'.
        }     
        if(i==num)          //If 'i' is not divisible by any number from 2 to num-1, then prints 'i'.
        {
            printf("%d\n", i);      
        }    
        num++;                  //Increments 'num' for next loop.
    }
}