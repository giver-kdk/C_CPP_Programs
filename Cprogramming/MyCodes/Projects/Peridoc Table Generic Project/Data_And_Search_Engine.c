/*
This program takes question and answer input from user and stores in file.
Users can access the data by following ways:
* Get all the question-answers in one print
* Access particular question-answer by searching keywords
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#define CHAR_LIMIT 100

void write_data();
void read_data();
void edit_data();
void store_loop();
int count_lines(FILE *fp);
void print_data(char topic[], FILE *fp, int line);
void search_engine(FILE *fp1, char word_group[50][50], int word_num, char file_name[], int new_line);
void split_string(char search[100], char group[50][50], int *num);
void descend_array(int array1[], int array2[], int size);
void dual_lineprint(FILE *fp, int line, int j);


int manage_data()
{
	char choice;
	printf("1) Write and store notes\t\t");
	Sleep(500);
	printf("2) Read and study notes\t\t");
	Sleep(500);
	printf("3) Edit and modify notes\n\n");
	Sleep(1000);
	printf("\t\t\t\tSelect your choice: ");
	fflush(stdin);
	scanf("%c", &choice);
	switch(choice)
	{
		case '1':
			write_data();
			break;
		case '2':
			read_data();
			break;
		case '3':
			edit_data();
			break;
		default:
			printf("\n\n\t\t\t\t\tWrong Choice!!!");
	}
}
void write_data()
{
	int i = 0;
	char file_name[50], choice, data, resume = 'y';
	printf("Write and Save Important Question Answers...Y/N?\n");
	scanf(" %c", &choice);
	
	if(choice == 'y' || choice == 'Y')
	{
		write:
		printf("Enter your Note ID Name: ");
		fflush(stdin);				//Clear buffer memory to avoid new line(Enter) as string input
		gets(file_name);
		FILE *fp1 = fopen(file_name, "r");
		if(fp1 == NULL)
		{
			//Data Store in file
			FILE *fp = fopen(file_name, "w");
			store_loop(fp);
			fclose(fp);
		}
		else
		{
			printf("\n\t\tThere already exists a Note with ID: %s\t\tTry different ID!\n", file_name);
			fclose(fp1);
			goto write;
		}
	}
}
void read_data()
{
	int new_line = 0, word_num = 0;
	char file_name[50], choice;
	char search_word[100], word_group[50][50];
	read:
	printf("\nEnter the Note ID Name to study: ");
	fflush(stdin);				//Clear buffer memory to avoid new line(Enter) as string input
	gets(file_name);
	FILE *fp1 = fopen(file_name, "r");
	if(fp1 == NULL)
	{
		printf("\nNo such Note available!\tPlease enter available Note ID\n");
		goto read;
	}
	new_line = count_lines(fp1);
	printf("\t\t\t\tHow do you want to access your question-answers?\n");
	Sleep(1000);
	printf("\t\t\t1. See all questions\t\t");
	Sleep(500);
	printf("2. Search by typing question\n\n");
	Sleep(500);
	printf("\t\t\t\tSelect your choice: ");
	scanf(" %c", &choice);
	switch(choice)
	{
		case '1':
			print_data(file_name, fp1, new_line);
			break;
		case '2':
			split_string(search_word, word_group, &word_num);
			search_engine(fp1, word_group, word_num, file_name, new_line);
			break;
		default:
			printf("Invalid Selection");
	}
	fclose(fp1);	
}
void edit_data()
{
	int i = 0, new_line = 0;
	char file_name[50], data, resume = 'y';
	edit:
	printf("\nEnter the Note ID Name to modify: ");
	fflush(stdin);				//Clear buffer memory to avoid new line(Enter) as string input
	gets(file_name);
	FILE *fp1 = fopen(file_name, "r");
	if(fp1 == NULL)
	{
		printf("\nNo such Note available!\tPlease enter available Note ID\n");
		goto edit;
	}
	fclose(fp1);
	fp1 = fopen(file_name, "a");
	store_loop(fp1);
}
void store_loop(FILE *fp1)
{
	char resume = 'y', data;
	int i;
	while(resume == 'y' || resume == 'Y')
	{
		i++;
		printf("Enter your Question:");
		printf("\t\t(Press 'Enter' to finish question)\n\n");
		fflush(stdin);
		while(1)
		{
			data = getchar();
			putc(data, fp1);
			if(data == '\n')
			{
				printf("\nWrite your answer:\n");
				fflush(stdin);
				while(1)
				{
					data = getchar();
					putc(data, fp1);
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
}
int count_lines(FILE *fp)
{
	char data;
	int new_line = 0;
	fseek(fp, 0, SEEK_SET);
	while((data = getc(fp)) != EOF)
	{
		if(data == '\n')
		{
			new_line++;
		}
	}
	fseek(fp, 0, SEEK_SET);
	return(new_line);
}
void print_data(char topic[], FILE *fp, int new_line)
{
	int count = 0, line_num = 0, i = 1;
	char data, bullet[] = "Question:";
	printf("Question Answers of %s are:\n\n", topic);
	printf("Question (%d) >>>>\n", i);
	while((data = getc(fp)) != EOF)
	{
		if(data == '\n')
		{
			line_num++;
			if(line_num == new_line)
			{
				printf(" ");
			}
			else if(strcmp(bullet, "Question:") == 0)
			{
				printf("\nAns:\t");
				strcpy(bullet, "Answer:");
			}
			else if(strcmp(bullet, "Answer:") == 0)
			{
				i++;
				printf("\n\nQuestion (%d) >>>>\t", i);
				strcpy(bullet, "Question:");
			}
		}
		printf("%c", data);
		count++;
		if(count >= CHAR_LIMIT && data == ' ')
		{
			count = 0;
			printf("\n");
		}
	}
}
void search_engine(FILE *fp1, char word_group[50][50], int word_num, char file_name[], int new_line)
{
	char file_word[50];
	char data;
	int i = 0, j = 0, k = 0, l = 0;
	int line_num = 1, match_num = 0, line[100] = {0}, match[100] = {0};
	while(1)	
	{
		fflush(stdin);
		data = fgetc(fp1);
		if(((data < 64 || data > 90) && (data < 97 || data > 122) && (data < 48 || data > 57)) || data == '\n')
		{
			file_word[i] = '\0';
			line[k] = line_num;
			if(data == '\n')
			{
				line_num++;
				k++;
				j++;
				match_num = 0;
			}
			if((strcmp(strlwr(file_word), strlwr(word_group[l]))) == 0)
			{
				match_num++;
				match[j] += match_num;
			}
			if(data == EOF)
			{
				fseek(fp1, 0, SEEK_SET);
				if(l == (word_num - 1))
				{
					goto one;
				}
				j = 0;
				k = 0;
				line_num = 1;
				l++;
			}
			strcpy(file_word, "\0");
			i = 0;
		}
		else
		{
			file_word[i] = data;
			i++;
		}
	}
	one:
	descend_array(line, match, new_line);
	for(i = 0 ; i < new_line; i++)
	{
		if(line[i] % 2 == 0)
		{
			if(match[i] != 0)
			{
				for(j = 0; j < new_line; j++)
				{
					if(line[j] == line[i] - 1)
					{
						if(match[j] != 0)
						{
							match[j] = 0;
						}
					}
				}
			}
		}
		else
		{
			if(match[i] != 0)
			{
				for(j = 0; j < new_line; j++)
				{
					if(line[j] == line[i] + 1)
					{
						if(match[j] != 0)
						{
							match[j] = 0;
						}
					}
				}
			}
		}
	}
	printf("\nSearch results from %s file are :>>>>>>>>>>", file_name);
	j = 0;
	for(i = 0; i < new_line; i++)
	{
		if(match[i] != 0)
		{
			j++;
			dual_lineprint(fp1, line[i], j);
		}
	}
}
void split_string(char search[100], char group[50][50], int *num)
{
	int i;
	char *ptr1;
	printf("Type your question/answer:\t\t\t(Atleast type some matching keywords)\n");
	fflush(stdin);
	gets(search);
	for(i = 0; search[i] != '\0'; i++)
	{
		if((search[i] < 64 || search[i] > 90) && (search[i] < 97 || search[i] > 122) && (search[i] < 48 || search[i] > 57))
		{
			search[i] = ' ';
		}
	}
	i = 0;
	ptr1 = strchr(search, ' ');
	if(ptr1 != NULL)
	{
		ptr1 = strtok(search, " ");
		while(ptr1 != NULL)
		{
			(*num)++;
			strcpy(group[i], ptr1);
			ptr1 = strtok(NULL, " ");
			i++;
		}
	}
	else
	{
		*num = 1;
		strcpy(group[i], search);
	}
}
void descend_array(int array1[], int array2[], int size)
{
	int i, j, temp1, temp2;

	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(array2[i] < array2[j])
			{
				temp1	  = array1[j];
				temp2	  = array2[j];
				array1[j] = array1[i];
				array2[j] = array2[i];
				array1[i] = temp1;
				array2[i] = temp2;
			}
		}
	}
}
void dual_lineprint(FILE *fp, int line, int j)
{
	int count = 1, limit = 0, char_num = 0, line_num = 0;
	char data;
	if(line % 2 == 0)
	{
		line = line - 1;
	}
	printf("\n\nQuestion (%d) >>>>\n", j);
	while((data= getc(fp)) != EOF)
	{
		if(data == '\n')
		{
			count++;
		}
		if(count == line)
		{
			if(line == 1)
			{
				fseek(fp, 0, SEEK_SET);
			}
			while((data= getc(fp)) != EOF)
			{
				if(data == '\n')
				{
					limit++;
					if(limit == 2)
					{
						goto end;
					}
					printf("\nAns:");
				}
				printf("%c", data);
				char_num++;
				if(char_num >= CHAR_LIMIT && data == ' ')
				{
					char_num = 0;
					printf("\n");
				}
			}
		}
	}
	end:
	fseek(fp, 0, SEEK_SET);
}

