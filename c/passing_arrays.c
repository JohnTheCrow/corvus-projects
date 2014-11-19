#include <stdio.h>

/* Passing an array (in this case a character array - or a string) between
 * functions. */

char * printString()
{
	char * string = "Hello!";
	return string;
}

int main(void)
{
	char * s = printString();
	printf("%s\n", s);
}

