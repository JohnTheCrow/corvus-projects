#include <stdio.h>

int largest(int * array, int length);
void add_three(int * num);

int main(int argc, char **argv)
{
	int var = 10;

/* When assigning pointer variables, the value should be a memory address. */
	int * p_var = &var; // p_var is a pointer to var

	printf("%x\n", p_var); // Prints address of var
	printf("%d\n", *p_var); // Prints value of var

/* We are able to change the value of var by dereferencing the pointer to
 * var. */
	*p_var += 5;

	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

/* Array variables are pointer constants, meaning the array name without a
 * subscript is a pointer to the beginning of the array. */

// This means that
	int * p_array = &array[0];
// and
	 p_array = array;
// are equivalent.

/* You can use basic arithmetic on pointers to access later elements
 * of an array. */
	printf("%d\n", *(p_array + 5)); // Prints the 5th element of array
/* This is called array pointer notation. Note that this works the same
 * regardless of the data type of the array. */

/* You can subtract one pointer from another pointer that points to an element
 * in the same array to determine how far apart they are. */
	int * p_array2 = array + 3;
/* Prints the number of elements between p_array2 and p_array. */
	printf("%d\n", p_array2 - p_array);
/* Note that this only works for pointers pointing to elements within the same
 * array. */

/* You must use pointers to pass arrays to functions. Remember that the name
 * of an array (without a subscript) is a pointer to the first element in the
 * array. */
	printf("The largest value in the array is %d.\n", largest(array, 10));

/* When passing a regular variable to a function, only a copy of the value is
 * passed. In other words, a called function cannot alter the value of a
 * variable in the calling function's scope. This is not so with arrays, or
 * with any function you pass by address. */
	int change_me = 5;
	add_three(&change_me); // change_me passed by address, not value.
	printf("%d\n", change_me); // change_me is altered despite its local scope.

	return 0;
}

int largest(int * array, int length)
{
	int count;
	int  biggest = array[0];

	for(count = 0; count < length; count++)
	{
		if(array[count] > biggest)
		{
			biggest = array[count];
		}
	}

	return biggest;
}

void add_three(int * num)
{
	*num += 3;
}
