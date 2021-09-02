#include <stdio.h>
union student
{
    char name[20];
    union gender
    {
        char g;
        union address
        {
            char add[20];
        }add1;
    }g1;
}s1;
void main()
{
    printf("Enter the name: ");
    scanf("%s",&s1.name);
    printf("Name: %s\n",s1.name);
    printf("Enter the gender: ");
    scanf(" %c",&s1.g1.g);
    printf("Gender: %c\n",s1.g1.g);
    printf("Enter the address: ");
    scanf("%s",s1.g1.add1.add);
    printf("Address: %s\n",s1.g1.add1.add);
}