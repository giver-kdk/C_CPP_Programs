#include <stdio.h>

static int a=10;
function1(int b)
{
    printf("%d", a*b);
}
function2()
{
    a++;            ///Update and run 10,11 codes
    function1(30);
}
int main()
{
    function2();
}