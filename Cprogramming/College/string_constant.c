#include <stdio.h>
void main()
{
    char s[10];
    printf("Enter you name: ");
    //scanf("%s", s);
    gets(s);
    printf("My name is %s", s);

}