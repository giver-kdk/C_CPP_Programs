#include <stdio.h>
#include <conio.h>

/*This program sorts array elements in Ascending Order.*/
void main()
{
    int size=5, temp, i, j, array[5];
    printf("Enter any five numbers: \n");
    for(i=0; i<=size-1; i++)
    {
        scanf("%d", &array[i]);
    }
    for(i=0; i<=size-2; i++)
    {
        for(j=0; j<=size-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("\nThe ascending order is: \n");
    for(i=0; i<=size-1; i++)
    {
        printf("%d\n", array[i]);
    }
}
/*NOTE: The elements of Array actually get arraged in Ascending Order inside memory array.*/