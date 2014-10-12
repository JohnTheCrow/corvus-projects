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
	int i, j, tmp, didSwap;

/* If no array elements were swapped, the list is already
 * sorted and the loop will break. */

	for(i = 0; i < 10; i++)
	{
		didSwap = 0;

		for(j = 0; j < 10; j++)
		{
			if(array[j] > array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				didSwap = 1;
			} // Swap i and j if j > i
		}

		if(didSwap == 0)
		{
			break;
		}
	}
} // End of bubbleSort()
