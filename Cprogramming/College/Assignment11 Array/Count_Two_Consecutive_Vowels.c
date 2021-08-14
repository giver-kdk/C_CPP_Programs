/*This is a program to count the number of occurrences of any two vowels in succession in a line of text. 
Eg:
“Please allow a studious girl to read behavioral science”
Such occurrences are ea, io, ou, ie.
Observe that in a word such as studious we have counted “io” and “ou” as two separate occurrences of two consecutive vowels.*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    int i, count = 0;
    char string[100], vowel[5] = "aeiou";
    printf("Write any sentence: ");
    gets(string);
    for(i = 0; string[i] != '\0'; i++)
    {
        if(strchr(vowel, string[i]) != NULL)
        {
            if(strchr(vowel, string[i + 1]) != NULL)
            {
                count++;
            }
        }
    }
    printf("Number of two successive vowels: %d", count);
}