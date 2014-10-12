#include <stdio.h> //Includes printf()
#include <stdlib.h>
#include <string.h> //Includes strlen()
#include <ctype.h> //Includes isalpha(), isdigit(), etc.

/* Populate two arrays with random numbers between 1 and 100. If any element
 * in array1 is in the 50s, let the user know its corresponding element in
 * array2. If no element in array1 is in the 50s, chastise the user. */

int main(void)
{
	srand(time(NULL));

	int array1[10] = {0};
	int array2[10] = {0};
	int found[10] = {0};
	int i = 0, ctr = 0;

	for(i = 0; i < 10; i++)
	{
		array1[i] = (rand() % 100) + 1;
		array2[i] = (rand() % 100) + 1;
	}

	for(i = 0; i < 10; i++)
	{
		if( array1[i] >= 50 && array1[i] <= 59)
		{
			found[i] = 1;
		}
	}

	for(i = 0; i < 10; i++)
	{
		if(found[i] == 1)
		{
			printf("An array element was in the 50s! The corresponding element in array2 is %d.\n", array2[i]);
		}
		else
		{
			ctr++;
		}
	}

	if(ctr == 10) //If none of the elements in array1 are in the 50s.
	{
		printf("You have failed miserably.\n");
	}
	else
	{
		printf("Just for fun, here are the two arrays:\n");
		for(i = 0; i < 10; i++)
		{
			printf("%d\t", array1[i]);
		}
		printf("\n");
		for(i = 0; i < 10; i++)
		{
			printf("%d\t", array2[i]);
		}
		printf("\n");
	}
}
