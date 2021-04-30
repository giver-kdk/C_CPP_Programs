<<<<<<< HEAD
#include <stdio.h>
int main()
{
    int a, b, mult;
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    mult=multiply(a,b);
    //printf("The mulitplication is: %d", mult);

    return 0;
}

int multiply(int a, int b)
{
    int m;
    m= a*b;
  //  return m;
}


=======
#include <stdio.h>
int main()
{
    int a, b, mult;
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    mult=multiply(a,b);
    printf("The mulitplication is: %d", mult);

   // return 0;
}

int multiply(int a, int b)
{
    int m;
    m= a*b;
  //  return m;
}


>>>>>>> 31a0cd55077ad1ba304e75cb49a460b4e3e75082
