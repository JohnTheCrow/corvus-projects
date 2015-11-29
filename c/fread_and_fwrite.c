#include <stdio.h>
#include <stdlib.h>

/*
 * The fread() and fwrite() functions can read and write binary data from
 * memory to a filesystem.
 */
 
/*
 * Populate an array, write its contents to disk, then read them back into a
 * separate array.
 */

int main(int argc, char *argv[])
{
	int array1[25], array2[25], i;

	/* Append "b" to the mode when reading and writing binary files. */
	FILE *fp = fopen("/tmp/data", "w+b");

	for(i = 0; i < 25; i++)
		array1[i] = i * i;

	fwrite(array1, sizeof(int), 25, fp);
	fseek(fp, 0, SEEK_SET); // set fp back to beginning of file
	fread(array2, sizeof(int), 25, fp);

	for(i = 0; i < 25; i++)
		printf("%d\n", array2[i]);

	return 0;
}
