/* Program to open a file, read its content one character at a time using fgetc() function and display it to screen*/
#include <stdio.h>

int main()
{
    char ch;
    int i;
    FILE *fp = fopen("Hello.txt", "r");
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
}