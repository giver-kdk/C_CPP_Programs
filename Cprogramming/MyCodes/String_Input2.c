#include <stdio.h>
void main()
{
    char s[10];
    printf("Enter you name: ");
    scanf("%[A-Z]", s);             //'%[A-Z]' only reads strings from A to Z
                                   // %[A-Z] will stop reading when string excluding from A-Z comes

    printf("My name is %s", s);

}