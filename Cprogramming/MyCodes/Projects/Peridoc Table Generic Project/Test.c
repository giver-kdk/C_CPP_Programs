#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	char string[] = "Hello World";
	strcpy(string, "\0");
	printf("%s", string);
}