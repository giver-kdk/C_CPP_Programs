/*This program opens the file named test.txt and adds to it the text “@TU” */
#include <stdio.h>
#include <conio.h>

int main()
{
    char string[50];
    FILE *fp = fopen("test.txt", "r");          //Open file in read mode to read and display current data
    fgets(string, 30, fp);
    printf("Current File Info: %s\n", string);
    fclose(fp);

    fp = fopen("test.txt", "a");                //Open file in append mode to add data
    fprintf(fp, "@TU");
    fclose(fp);

    fp = fopen("test.txt", "r");                
    fgets(string, 30, fp);
    printf("Modified File Info: %s", string);
    fclose(fp);
}