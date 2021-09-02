#include <stdio.h>
#include <string.h>
#include <conio.h>

union student
{
    char name[20];
    int roll_num;
    int salary;
};
void display(union student s1, union student s2, union student s3, union student s4)                         //Function with character pointer(string) as arguments
{   
    int a, b, c;                  
    printf("Enter name: ");    
    gets(s1.name);
    a = strcmp(strlwr(s1.name), strlwr(s2.name));
    b = strcmp(strlwr(s1.name), strlwr(s3.name));
    c = strcmp(strlwr(s1.name), strlwr(s4.name));
    // printf("%d\t%d\t%d", a, b, c);
    if(a == 1 || b == 1 || c == 1)
    {
        printf("Enter Roll Number: ");
        scanf("%d", &s1.roll_num);
        if(s1.roll_num == 57 && a == 1)
        {
            printf("Your Salary is: %d", s2.salary);
        }
        else if(s1.roll_num == 58 && b == 1)
        {
            printf("Your Salary is: %d", s3.salary);
        }
        else if(s1.roll_num == 59 && c == 1)
        {
            printf("Your Salary is: %d", s4.salary);
        }
        else
        {
            printf("Invalid Roll Number");
        }
    }
}

int main()
{
    union student a1, a2, a3, a4;                  
    strcpy(a2.name, "Ram");
    strcpy(a3.name, "Vam");
    strcpy(a4.name, "Aam");
    a2.roll_num = 57;
    a3.roll_num = 58;
    a4.roll_num = 59;
    a2.salary = 50000;
    a3.salary = 55000;
    a4.salary = 60000;
    display(a1, a2, a3, a4);
}