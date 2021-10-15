#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	int i, j, k = 50;
	struct _COORD COORD = {0, 0};
	system("cls");
	for(i=1;i<=100;++i)
    {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLOADING %d %%\n", i);
		if(i % 2 == 0)
		{
			printf("\t\t\t\t\t\t");
			for(j = 0; j <= i / 2; j++)
			{
				printf("%c", 223);
			}
			for(k = 50 - j; k > 0 ; k--)
			{
				printf("~");
			}
		}
		if(i == 1)
		{
			Sleep(1000);
		}
		if(i == 5)
		{
			Sleep(250);
		}
		if(i == 25)
		{
			Sleep(400);
		}
		if(i == 60)
		{
			Sleep(400);
		}
		if(i == 100)
		{
			Sleep(1000);
		}
		if(i != 100)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD);
		}
    }
}