#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int*);

void main()
{
	int array[10] = {0};
	int i;
	for(i = 0; i < 10; i++)
		array[i] = rand() % 100;

	bubbleSort(array);

	for(i = 0; i < 10; i++)
		printf("%d\t", array[i]);

	printf("\n");
}

void bubbleSort(int *array)
{
	int i, j, tmp;

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(array[j] > array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			} // Swap i and j if j > i
		}
	}
} // End of bubbleSort()
