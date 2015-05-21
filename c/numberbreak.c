#include <stdio.h>
#include <stdlib.h>

/* Take a random number and put each of its individual digits in a separate
 * array element. */

int main(int argc, char **argv)
{
	srand(time(NULL));

	int number = rand();
	int place = 1000000000;
	int digit[10];
	int i;

//	printf("%d\n", number);

	for(i = 0; i < 10; i++)
	{
		digit[i] = number / place;
		number = number - (digit[i] * place);
		place /= 10;
	}

	for(i = 0; i < 10; i++)
	{
		if(digit[i] != 0)
			break;
	}

	for(; i < 10; i++)
		printf("%d ", digit[i]);
	printf("\n");

	return 0;
}
