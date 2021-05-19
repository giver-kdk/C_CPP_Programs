#include <stdio.h>
#include <conio.h>

void main()
{
    int s1, s2, s3, s4, s5, per;
    printf("Enter the marks obtained in five subjects: ");
    scanf("%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5);
    per= (s1+s2+s3+s4+s5)/5;
    if(per>=80)
    {
        printf("Distinction");
    }
    else if(per>=70)
    {
        printf("First Division");
    }
    else if(per>=60)
    {
        printf("Second Division");
    }
    else if(per<=50 && per>=40)
    {
        printf("Third Division");
    }
    else
    {
        printf("Fail!");
    }
}