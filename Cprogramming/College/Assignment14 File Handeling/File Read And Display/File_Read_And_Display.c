/*This program opens the file named test.txt, read its content and display it to screen */
#include <stdio.h>
#include <conio.h>

int main()
{
    char string[50];
    FILE *fp = fopen("test.txt", "r");          //Open file in read mode
    fgets(string, 30, fp);                      //Stores 30 characters from file in 'string'
    printf("Information of file: %s", string);
    fclose(fp);
}