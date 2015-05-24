#include <stdio.h>
#include <string.h>

/* Take line 1 in files 1 and 2 and print them on one line. Do same
 * for all lines of file. Currently adds a space between the two strings and
 * performs no error checking whatsoever. */

//TODO: Check that argv contains exactly two elements
//TODO: Allow for more than two files to be recombobulated (negates above TODO)
//TODO: Allow for choice of delimiter between same-line strings

int main(int argc, char **argv)
{

	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");
	char buffer1[80], buffer2[80];

	while(fgetc(file1) != EOF)
	{
		fseek(file1, -1, SEEK_CUR);
		fgets(buffer1, 80, file1);
		buffer1[strlen(buffer1)-1] = '\0';
		fgets(buffer2, 80, file2);
		buffer2[strlen(buffer2)-1] = '\0';
		printf("%s %s\n", buffer1, buffer2);
	}

	fclose(file1);
	fclose(file2);

	return 0;
}
