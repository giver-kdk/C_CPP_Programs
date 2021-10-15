#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	int i = 0, j = 0, k = 0, l = 0, count = 0;
	int word_num = 0, line_num = 1, match_num = 0, line[100] = {0}, match[100] = {0};
	char file_name[50], choice, data, resume = 'y', answer[20] = "Answer:";
	char file_word[50], search_word[50], word_group[50][50];
	char *ptr1, *ptr2;
	printf("Write and Save Important Question Answers...Y/N?\n");
	scanf(" %c", &choice);
	
	if(choice == 'y' || choice == 'Y')
	{
		printf("Enter the note name: ");
		fflush(stdin);				//Clear buffer memory to avoid new line(Enter) as string input
		gets(file_name);
		FILE *fp = fopen(file_name, "w");
		while(resume == 'y' || resume == 'Y')
		{
			i++;
			printf("Enter Question Number %d:", i);
			printf("\t\t(Press 'Enter' to finish question)\n\n");
			fflush(stdin);
			while(1)
			{
				data = getchar();
				putc(data, fp);
				if(data == '\n')
				{
					printf("\nWrite your answer:\n");
					fflush(stdin);
					while(1)
					{
						data = getchar();
						putc(data, fp);
						if(data == '\n')
						{
							goto resume;
						}
					}
				}
			}
			resume:
			printf("Do you want to add more...Y/N?");
			scanf(" %c", &resume);
		}
		fclose(fp);
	}
	choice = 'n';
	printf("Wan to see your %s notes...Y/N?", file_name);
	scanf(" %c", &choice);
	FILE *fp1 = fopen(file_name, "r");
	if(choice == 'y' || choice == 'Y')
	{
		printf("1) See all questions\t\t2)Search by typing question:\n\n");
		scanf(" %c", &choice);
		switch(choice)
		{
			case '1':
				printf("Question Answers of %s are:\n\n", file_name);
				printf("Question:\n");
				while((data= getc(fp1)) != EOF)
				{
					if(data == '\n')
					{
						printf("\n%s\t", answer);
						strcpy(answer, "");
					}
					printf("%c", data);
					count++;
					if(count >= 100 && data == ' ')
					{
						count = 0;
						printf("\n");
					}
				}
				break;
			case '2':
				i = 0;
				printf("Type your question/answer:\t\t\t(Atleast type some matching keywords)\n");
				fflush(stdin);
				gets(search_word);
				ptr1 = strchr(search_word, ' ');
				if(ptr1 != NULL)
				{
					ptr1 = strtok(search_word, " ");
					while(ptr1 != NULL)
					{
						strcpy(word_group[i], ptr1);
						ptr1 = strtok(NULL, " ");
						i++;
						word_num++;
					}
				}
				else
				{
					strcpy(word_group[i], search_word);
					word_num++;
				}
				i = 0;
				while(1)
				{
					// fflush(stdin);
					data = fgetc(fp1);
					if(data == EOF)
					{
						if(l >= word_num)
						{
							goto one;
						}
						l++;
					}
					else if(data == ' ' || data == '.' || data == '?' || data == '\n')
					{
						file_word[i] = '\0';
						if((strcmp(file_word, word_group[l])) == 0)
						{
							match_num++;
							match[j] = match_num;
							line[k] = line_num;
							// break;
						}
						if(data == '\n')
						{
							line_num++;
							k++;
							j++;
							match_num = 0;
							// break;
						}
						goto loop;
					}
					file_word[i] = data;
					loop:
					i++;
				}
				one:
				for(i = 0; i < 5; i++)
				{
					printf("%d\t", line[i]);
				}
				printf("\n");
				for(i = 0; i < 5; i++)
				{
					printf("%d\t", match[i]);
				}
		}
	}
	fclose(fp1);
}
