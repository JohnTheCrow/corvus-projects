#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POOLSZ 10

/*
 * This file attempts to explain qsort() and bsearch(), both provided
 * by stdlib.h. qsort() sorts an array in ascending order and bsearch()
 * performs a binary search of a sorted array for a given element, or "key".
 * Both functions take as their last argument a function that takes two
 * arguments and returns an int < 0 if arg1 < arg2, returns 0 if arg1 == arg2,
 * or an int > 0 if arg1 > arg2.
 */

int numcmp(const void *item1, const void *item2);

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int array[POOLSZ] = {0};
    int i, key, *found;

    for(i = 0; i < POOLSZ; i++)
        array[i] = rand() % 100;

/*
    for(i = 0; i < POOLSZ; i++)
        printf("%d ", array[i]);
    printf("\n");
*/

	qsort(array, POOLSZ, sizeof(int), numcmp);
	
/*
	for(i = 0; i < POOLSZ; i++)
		printf("%d ", array[i]);
	printf("\n");
*/

	printf("Enter number to search for (0-99): ");
	scanf("%d", &key);

/*
 * bsearch() returns a void pointer to the matching member of the array, so
 * cast it as necessary if you need to use it later. If the member is not found
 * in the array, bsearch() returns NULL.
 */

	found = (int *)bsearch(&key, array, POOLSZ, sizeof(int), numcmp);

	if(!found) {
		printf("Number not found in array.\n");
		return 1;
	} else {
	printf("Number found: %d\n", *found);
	}

	return 0;
}

/*
 * Both qsort() and bsearch() expect the comparison function to take two const
 * void pointers as arguments, so cast as necessary.
 */

int numcmp(const void *item1, const void *item2)
{
	return *(int *)item1 - *(int *)item2;
}
