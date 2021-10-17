#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <windows.h>
#include <direct.h>
#include <process.h>

typedef struct Employee
{
	char empId[15];
	char fname[20];
	char lname[20];
	int age;
	float bsal;
	long phone;
}Employee;
FILE *fp;
Employee emp;
char fileName[] = "EMP.txt";
char tempFileName[] = "temp.txt";
/*Functions used in project*/
void AddEmployee();
void ListEmployee();
void SearchEmployee();
void ModifyEmployee();
void DeleteEmployee();
void gotoxy(short int x, short int y);
void first();
char file();

int main()
{
	char ch = 'a';
	system("cls");
	first();
	fp = fopen(fileName, "rb+");
	if(fp == NULL)
	{
		fp = fopen(fileName, "wb+");
		if(fp == NULL)
		{
			printf("Can't Open File");
			exit(0);
		}
	}
	while(ch != '6')
	{
		ch = file();
		switch(ch)
		{
			case '1':
				AddEmployee();
				break;
			case '2':
				ListEmployee();
				break;
			case '3':
				SearchEmployee();
				break;
			case '4':
				ModifyEmployee();
				break;
			case '5':
				DeleteEmployee();
				break;
			case '6':
				exit(0);
				break;
			default:
				system("Color 04");			/*4 = RED*/
				gotoxy(30, 10);
				printf("WRONG CHOICE");
				getch();
				break;
		}
	}
	return 0;
}
void AddEmployee()
{
	char another, ch;
	do
	{
		system("cls");
		fseek(fp, 0, SEEK_END);
		another = 'Y';
		gotoxy(25, 3);
		system("Color 04");			
		printf("ADD EMPLOYEE RECORD");
		gotoxy(25,6);
		system("Color 02");						/*2 = GREEN*/
		fflush(stdin);
		printf("1.ENTER EMPLOYEE ID: ");
		gets(emp.empId);
		gotoxy(25, 7);
		fflush(stdin);
		printf("2.ENTER FIRST NAME OF EMPLOYEE: ");
		gets(emp.fname);
		gotoxy(25, 8);
		fflush(stdin);
		printf("3.ENTER LAST NAME OF EMPLOYEE: ");
		gets(emp.lname);
		gotoxy(25, 9);
		fflush(stdin);
		printf("4.ENTER AGE OF EMPLOYEE: ");
		scanf("%d", &emp.age);
		gotoxy(25, 10);
		fflush(stdin);
		printf("5.ENTER SALARY OF EMPLOYEE: ");
		scanf("%f", &emp.bsal);
		gotoxy(25, 11);
		fflush(stdin);
		printf("5.ENTER PHONE OF EMPLOYEE: ");
		scanf("%ld", &emp.phone);
		gotoxy(25, 15);
		system("Color 05");						/*5 = MAGENTA*/
		printf("SAVE CHANGES (y/n)?");
		ch = getche();
		if(ch == 'y' || ch == 'Y')
		{
			fwrite(&emp, sizeof(emp), 1, fp);
			fflush(stdin);
		}
		gotoxy(28, 15);
		system("cls");
		printf("ADD ANOTHER EMPLOYEE (y/n)?");
		// fflush(stdin);
		// another = getche();
		fflush(stdin);
		another = getche();
		// fflush(stdin);
		system("Color 015");						/*15 = WHITE*/
	}while(another == 'Y' || another == 'y');
}
//Continue from page number 383. Start new function: void ListEmployee()
void ListEmployee()
{
	int i;
	system("cls");
	fseek(fp, 0, SEEK_SET);
	system("Color 04");
	gotoxy(1, 1);
	printf("LIST OF EMPLOYEE RECORD");
	system("Color 02");
	gotoxy(1, 2);
	printf("EMP ID");
	gotoxy(14, 2);
	printf("FIRST NAME");
	gotoxy(27, 2);
	printf("LAST NAME");
	gotoxy(40, 2);
	printf("AGE");
	gotoxy(53, 2);
	printf("SALARY");
	gotoxy(66, 2);
	printf("PHONE");
	for(i = 1; i <= 80; i++)
	{
		system("Color 014");							/*14 = YELLOW*/
		gotoxy(i, 3);
		printf("-");
	}
	i = 4;
	while(fread(&emp, sizeof(emp), 1, fp) != 0)
	{
		gotoxy(1, i);
		printf("%s", emp.empId);
		gotoxy(14, i);
		printf("%s", emp.fname);
		gotoxy(27, i);
		printf("%s", emp.lname);
		gotoxy(40, i);
		printf("%d", emp.age);
		gotoxy(53, i);
		printf("%.2f", emp.bsal);
		gotoxy(66, i);
		printf("%ld", emp.phone);
		i++;
	}
	fflush(stdin);
	getche();
}
void SearchEmployee()
{
	int i, datafound = 0;
	char employeeId[15];
	char another, ch;
	do
	{

		system("cls");
		fseek(fp, 0, SEEK_SET);
		gotoxy(1, 1);
		system("Color 04");
		printf("SEARCH EMPLOYEE RECORD: ");
		gotoxy(5, 2);
		system("Color 02");
		fflush(stdin);
		printf("ENTER EMPLOYEE ID: ");
		gets(employeeId);
		while(fread(&emp, sizeof(emp), 1, fp) != 0)
		{
			if(strcmp(emp.empId, employeeId) == 0)
			{
				datafound = 1;
				break;
			}

		}
		if(datafound == 1)
		{
			system("Color 04");
			gotoxy(4, 4);
			printf("RECORD OF EMPLOYEE");
			system("Color 02");
			gotoxy(4, 5);
			printf("--------------------------");
			gotoxy(4, 6);
			printf("EMPLOYEE ID: ");
			printf("%s", emp.empId);
			gotoxy(4, 7);
			printf("FIRST NAME: ");
			printf("%s", emp.fname);
			gotoxy(4, 8);
			printf("LAST NAME: ");
			printf("%s", emp.lname);
			gotoxy(4, 9);
			printf("AGE: ");
			printf("%d", emp.age);
			gotoxy(4, 10);
			printf("BASIC SALARY: ");
			printf("%.2f", emp.bsal);
			gotoxy(4, 11);
			printf("PHONE: ");
			printf("%ld", emp.phone);
		}
		else
		{
			gotoxy(10, 8);
			printf("EMPLOYEE NOT FOUND!!!");
		}
		gotoxy(25, 15);
		system("Color 04");
		printf("SEARCH ANOTHER EMPLOYEE (y/n)?");
		fflush(stdin);
		another = getche();
		fflush(stdin);
		system("Color 015");										/*15 = WHITE*/
	}while(another == 'Y' || another == 'y');
}
void ModifyEmployee()
{
	int i, datafound = 0, recordNo = 0;
	char employeeId[15];
	char another, ch;
	do
	{
		system("cls");
		fseek(fp, 0, SEEK_SET);
		rewind(fp);
		gotoxy(1, 1);
		system("Color 04");
		printf("MODIFY EMPLOYEE RECORD: ");
		system("Color 02");
		gotoxy(2, 2);
		fflush(stdin);
		printf("ENTER EMPLOYEE ID TO BE MODIFIED: ");
		gets(employeeId);
		while(fread(&emp, sizeof(emp), 1, fp) == 1)
		{
			if(strcmp(emp.empId, employeeId) == 0)
			{
				datafound = 1;
				break;
			}
			recordNo++;
		}
		if(datafound == 1)
		{
			gotoxy(5, 3);
			system("Color 04");
			printf("OLD RECORD IS: ");
			gotoxy(5, 4);
			system("Color 02");
			printf("EMPLOYEE ID: ");
			printf("%s", emp.empId);
			gotoxy(5, 5);
			printf("FIRST NAME: ");
			printf("%s", emp.fname);
			gotoxy(5, 6);
			printf("LAST NAME: ");
			printf("%s", emp.lname);
			gotoxy(5, 7);
			printf("AGE: ");
			printf("%d", emp.age);
			gotoxy(5, 8);
			printf("BASIC SALARY: ");
			printf("%.2f", emp.bsal);
			gotoxy(5, 9);
			printf("PHONE: ");
			printf("%ld", emp.phone);
			gotoxy(5, 11);
			system("Color 04");
			printf("ENTER NEW INFORMATION: ");
			gotoxy(5, 12);
			system("Color 02");
			printf("EMPLOYEE ID: ");
			gets(emp.empId);
			gotoxy(5, 13);
			printf("FIRST NAME: ");
			gets(emp.fname);
			gotoxy(5, 14);
			printf("LAST NAME: ");
			gets(emp.lname);
			gotoxy(5, 15);
			printf("AGE: ");
			scanf("%d", &emp.age);
			gotoxy(5, 16);
			printf("BASIC SALARY: ");
			scanf("%f", &emp.bsal);
			gotoxy(5, 17);
			printf("PHONE: ");
			scanf("%ld", &emp.phone);
			fseek(fp, sizeof(emp) * (recordNo), SEEK_SET);
			gotoxy(5, 19);

			if(fwrite(&emp, sizeof(emp), 1, fp) == 1)
			{
				printf("THE RECORD HAS BEEN MODIFIED!!!");
			}
			else
			{
				printf("ERROR DURING MODIFICATION!!!");
			}
		}
		else
		{
			gotoxy(10, 19);
			printf("EMPLOYEE NOT FOUND");
		}
		gotoxy(10, 21);
		system("Color 04");
		printf("MODIFY ANOTHER EMPLOYEE (y/n)?");
		fflush(stdin);
		system("Color 015");										/*15 == WHITE*/
	}while(another == 'Y' || another == 'y');
}
void DeleteEmployee()
{
	int i, datafound = 0;
	char employeeId[15];
	FILE *fpTemp;
	char another, ch;
	do
	{
		system("cls");
		fseek(fp, 0, SEEK_SET);
		rewind(fp);
		system("Color 04");
		gotoxy(1, 1);
		printf("DELETE EMPLOYEE RECORD");
		system("Color 02");
		gotoxy(2, 2);
		fflush(stdin);
		printf("ENTER EMPLOYEE ID TO BE DELETED: ");
		gets(employeeId);
		while(fread(&emp.empId, sizeof(emp), 1, fp) == 1)
		{
			if(strcmp(emp.empId, employeeId) == 0)
			{
				datafound = 1;
				break;
			}
		}
		if(datafound == 1)
		{
			fpTemp = fopen(tempFileName, "wb");
			rewind(fp);
			while(fread(&emp, sizeof(emp), 1, fp) == 1)
			{
				if(strcmp(emp.empId, employeeId) != 0)
				{
					fwrite(&emp, sizeof(emp), 1, fpTemp);
				}
			}
			fclose(fp);
			fclose(fpTemp);
			remove(fileName);
			rename(tempFileName, fileName);
			fp = fopen(fileName, "rb+");
			gotoxy(6, 8);
			printf("SUCCESSFULLY DELETED!!!");
		}
		else
		{
			gotoxy(2, 6);
			printf("EMPLOYEE NOT FOUND!!!");
		}
		gotoxy(10, 20);
		system("Color 04");
		printf("DELETE ANOTHER EMPLOYEE(y/n)?");
		fflush(stdin);
		another = getche();
		fflush(stdin);
		system("Color 015");
	}while(another == 'Y' || another == 'y');
}
void first()
{
	int gd = DETECT, gm;
	char data[] = "C:\\MINGw\\lib\\libbgi.a";
	char empInfo[] = "EMPLOYEE INFORMATION SYSTEM";
	char developed[]  = "DEVELOPED BY: ";
	char giver[] = "GIVER KHADKA";
	char bar[] = ">>>>>>>>>>>>>";
	initgraph(&gd, &gm, data);
	setcolor(2);
	settextstyle(4, 0, 1);
	outtextxy(80, 190, empInfo);
	settextstyle(1, 0, 1);
	setcolor(4);
	outtextxy(480, 370, developed);
	setcolor(1);									/*1 = BLUE*/
	outtextxy(400, 370, giver);
	outtextxy(400, 400, bar);
	getch();
	restorecrtmode();
	closegraph(0);
}
char file()
{
	int gd = DETECT, gm;
	char data[] = "C:\\MINGw\\lib\\libbgi.a";
	char i;
	char empInfo[] = "EMPLOYEE INFORMATION SYSTEM";
	char menu[]  = "MAIN MENU";
	char op1[] = "1>>ADD EMPLOYEE RECORD.";
	char op2[] = "2>>LIST RECORD OF ALL EMPLOYEE.";
	char op3[] = "3>>SEARCH A PARTICULAR EMPLOYEE.";
	char op4[] = "4>>MODIFY INFORMATION OF A EMPLOYEE.";
	char op5[] = "5>>DELETE A EMPLOYEE.";
	char op6[] = "6>>EXIT SYSTEM.";
	char choice[] = "ENTER YOUR CHOICE";
	initgraph(&gd, &gm, data);
	setcolor(4);
	setcolor(2);
	settextstyle(7, 0, 2);
	outtextxy(130, 45, empInfo);
	settextstyle(7, 0, 3);
	setcolor(14);								/*14 = YELLOW*/
	outtextxy(260, 95, menu);
	settextstyle(0, 0, 0);
	setcolor(5);								/*5 = MAGENTA*/
	outtextxy(200, 145, op1);
	outtextxy(200, 170, op2);
	outtextxy(200, 195, op3);
	outtextxy(200, 220, op4);
	outtextxy(200, 245, op5);
	outtextxy(200, 270, op6);
	setcolor(2);
	outtextxy(200, 360, choice);
	fflush(stdin);
	i = getche();
	restorecrtmode();
	closegraph(0);
	return(i);
}
void gotoxy(short int x, short int y)
{
  static HANDLE h = NULL;  
  if(!h)
  {
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  }
  COORD c = {x, y};  
  SetConsoleCursorPosition(h,c);
}