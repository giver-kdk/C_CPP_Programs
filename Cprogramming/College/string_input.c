#include <stdio.h>
void main()
{
    char s[10];
    printf("Enter you name: ");
    //scanf("%s", s);             //'%s' can't print full name cause it will stop reading input when whitespace comes
    //scanf("^\n");              //This can print full name cause '^' means exclude. 
                                //The scanf("^\n") will read strings until a new line string comes
    gets(s);                   //gets(s) will read all type of strings including whitespace
    printf("My name is %s", s);

}