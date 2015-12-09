#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int num, ...);

int main(int argc, char *argv[])
{
	int x = 0;

	x = sum(5, 1, 2, 3, 4, 5);
	printf("%d\n", x);

	x = sum(7, 1, 2, 3, 4, 5, 6, 7);
	printf("%d\n", x);

	return 0;
}

int sum(int num, ...)
{
	int i, x = 0;

/* va_list is a pointer type to later access the individual arguments. */
	va_list arg_ptr;

/* Initialize arg_ptr to the first initial variable by passing in the last
 * fixed variable. */
	va_start(arg_ptr, num);

/* va_arg takes the arg_ptr and the variable type as arguments. It returns the
 * value of the variable argument. */
	for(i = 0; i < num; i++)
		x += va_arg(arg_ptr, int);

/* va_end() cleans up the pointer. */
	va_end(arg_ptr);

	return x;
}
