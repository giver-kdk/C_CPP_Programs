#include <stdio.h>
#include <conio.h>
void main()
{
    int a=3, b=2;
    printf("The new added 'a' is: %d", a+=b);         //a+=b means a=a+b. So a=3+2=5
    printf("\nThe new subtracted 'a' is: %d", a-=b);  //a-=b means a=a-b. So a= 5-2=3. (Since previously 'a' was 5)
}