#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int max=6, min=1, num, start;
    srand(time(0));
    printf("Enter 1 to roll the Dice!!!");
    scanf("%d", &start);
    while (start==1)
    {
        num= (rand() %(max-min+1))+ min;
        printf("\n\t------The Dice showed %d-------", num);
        printf("\n\n\nEnter 1 to roll the Dice!!!");
        scanf("%d", &start);
        }
    printf("See You Soon!!!");
    getche();
}

