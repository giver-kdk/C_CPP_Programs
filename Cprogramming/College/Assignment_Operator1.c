#include <stdio.h>
#include <conio.h>
void main()
{
    int a=1, b=2, c=4, d=2, e=5, f=3, g=12, h=6, i=10, j=5;   
      
    printf("The sum of a and b is: %d", a+=b);         //a+=b means a=a+b. So a=3+2=5
    printf("\nThe difference of  c and d is: %d", c-=d);  //a-=b means a=a-b. So a= 5-2=3. (Since previously 'a' was 5)
    printf("The multiplication of e and f is: %d", +=b);         //a+=b means a=a+b. So a=3+2=5
    printf("\nThe division of g and h is: %d", a-=b);
    printf("The remainder of i and j is: %d", a+=b);         //a+=b means a=a+b. So a=3+2=5
}