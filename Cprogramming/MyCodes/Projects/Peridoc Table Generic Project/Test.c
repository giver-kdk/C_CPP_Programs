#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	int array1[] = {1, 2, 3, 4, 5}, array2[] = {2, 0, 0, 1, 3};
	int i, j, temp1, temp2;
	for(i = 0; i < 5; i++)
	{
		for(j = i + 1; j < 5; j++)
		{
			if(array2[i] < array2[j])
			{
				temp1 = array1[j];
				temp2 = array2[j];
				array1[j] = array1[i];
				array2[j] = array2[i];
				array1[i] = temp1;
				array2[i] = temp2;
			}
		}
	}
}