#include <stdio.h>
#include <stdlib.h>

int sumarrays(int * array1, int * array2, int count);
int * addarrays(int * array1, int * array2, int count);

int main(int argc, char **argv)
{
	srand(time(NULL));

	int array1[10], array2[10];
	int i;

	for(i = 0; i < 10; i++)
	{
		array1[i] = (rand() % 100) + 1;
		array2[i] = (rand() % 100) + 1;
	}

	int * array3 = addarrays(array1, array2, 10);

	printf("The sum of every number in both arrays is %d.\n", sumarrays(array1, array2, 10));
	printf("The sum of each parallel element in the arrays is");
	for(i = 0; i < 10; i++)
	{
		printf(" %d", array3[i]);
	}
	printf("\n");

	return 0;
}

/* Sum all values from two arrays and return the value. Assumes arrays are
 * the same size. count is the number of elements in each array. */
int sumarrays(int * array1, int * array2, int count)
{
	int total = 0;
	int i;

	for(i = 0; i < count; i++)
	{
		total += array1[i] + array2[i];
	}

	return total;
}

/* Sum parallel elements of two arrays and return the values in a 
 * third array. */
int * addarrays(int * array1, int * array2, int count)
{
	static int array3[10]; // Why does this need to be static?
	int i;

	for(i = 0; i < count; i++)
	{
		array3[i] = array1[i] + array2[i];
	}

	return array3;
}

/* I spoke with cmitchel++ about why array3 needed to be static in
 * addarrays(). The theory is that since we're returning a location in memory,
 * and the function that wrote to that address has exited after it returns
 * the address, the values in that address (and subsequent addresses) can not
 * be considered valid unless the variable is static. */
