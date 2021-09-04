/*This program creates file and stores data in it.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    FILE *fp;
    fp = fopen("Cprogram.txt", "w");                //Cprogram.txt file is created
    if(fp == NULL)                                  //If file creation fails
    {
        printf("Error");
        exit(1);               
    }
    printf("Enter the Number: ");
    scanf("%d", &a);
    fprintf(fp, "%d", a);                           //Entered number(data) is stored in file
    fclose(fp);
}