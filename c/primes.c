#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Test to see if a number is prime. */

int main(int argc, char *argv[])
{
	printf("%10u is prime.\n", 2);
	int i, j;

	for (j = 3; j <= UINT_MAX; j += 2) {

		for (i = 2; i < j; i++) 
			if (j % i == 0)
				break;
		
		if (i == j)
			printf("%10u is prime.\n", j);
	}

	return 0;
}
