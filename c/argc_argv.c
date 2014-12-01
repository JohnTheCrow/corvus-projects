#include <stdio.h>
#include <stdlib.h>

// argc is the number of arguments. The command itself is argument 0.
// argv is an array of the arguments (i.e. an array of strings).

/* Print every argument (not including the name of the command itself) on a
 * separate line. */
int main(int argc, char **argv)
{
	int i;

	for(i = 1; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
}
