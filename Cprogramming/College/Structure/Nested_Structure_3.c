/*This program uses nested structure in another way*/
#include <stdio.h>

struct student
{
    char name[20];
    struct gender
    {
        char g;
        struct address
        {
            char address[20];
        }add_num1;
    }g1;
}s1;

int main()
{
    struct student s2, s3;
    
}