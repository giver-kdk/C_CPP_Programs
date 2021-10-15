#include <stdio.h>
#include <conio.h>

int main()
{
	FILE *fp = fopen("Test.txt", "r");
	char data;
	data = fgetc(fp);
	printf("%c", data);
}