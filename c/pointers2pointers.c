#include <stdio.h>
#include <stdlib.h>

/* Write a program that declares a 12x12 array of characters. Place X's in
 * every other element. Use a pointer to the array to print the values to the
 * screen in a grid format. */

int main(int argc, char **argv)
{
	char yep[12][12];
	char *p = *yep;
	int i, j;

	for(i = 0; i < 12; i++)
	{
		for(j = 0; j <12; j++)
		{
			if((j % 2) == 0)
				yep[i][j] = 'X';
			else
				yep[i][j] = ' ';
		}
	}

	for(i = 0; i < 12; i++)
	{
		for(j = 0; j < 12; j++)
		{
			printf("%c", *p++);
		}

		printf("\n");
	}

	return 0;
}
