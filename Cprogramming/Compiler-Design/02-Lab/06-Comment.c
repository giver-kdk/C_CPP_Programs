/*Write a C program to identify wheather a given line is a comment or not */

/* logic
1. Read the input string.
2. Check wheather the string is starting '/' and check next character is '/'or '*'
3. If condition satisfies print comment.
4. Else not a comment. */

#include <stdio.h>
#include <conio.h>

void main()
{
	char comment[30];
	int i = 2, a = 0;
	printf("\nEnter a comment: ");
	gets(comment);
	// scanf(comment);

	if (comment[0] == '/')
	{
		if (comment[1] == '/')
			printf("\n It is a comment");
		else if (comment[1] == '*')
		{
			for (i = 2; i <= 30; i++)
			{
				if (comment[i] == '*' && comment[i + 1] == '/')
				{
					printf("\n It is a comment ");
					a = 1;
					break;
				}
				else continue;
			}
			if (a == 0)
				printf("\n It is not a comment");
		}
		else
			printf("\n It is not a comment");
	}
	else
		printf("\n It is not a comment");
	// getch();
	printf("\n***** Name: Giver Khadka *****");
}
