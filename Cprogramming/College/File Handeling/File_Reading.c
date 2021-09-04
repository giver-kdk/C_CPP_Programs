/*This program allows to create a file, write the file and read the file.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    //If file doesn't exist. Then, 'fopen' returns NULL in read mode
    FILE *fp = fopen("Cprogram.txt", "w");
    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    while((ch = getchar()) != EOF)      //Continue while loop until end of file
    {
        putc(ch, fp);                   //Press Ctrl + Z foe EOF
    }
    fclose(fp);

    fp = fopen("Cprogram.txt", "r");
    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    while((ch = getc(fp)) != EOF)      //Continue while loop until end of pointed file
    {   //Content is now stored in 'ch'
        printf("%c", ch);               
    }
    fclose(fp);
}