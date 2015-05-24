#include <stdio.h>
#include <string.h>

/* Take line 1 in files 1 and 2 and print them on one line. Do same for all
 * lines of file. Currently uses a space for the delimiter. No checking is
 * performed to see if files have the same number of lines and behavior
 * unpredictable if this is the case. */

//TODO: Allow for more than two files to be recombobulated
//TODO: Allow for choice of delimiter between same-line strings

int main(int argc, char **argv)
{

	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");
	char buffer1[80], buffer2[80];

	if(argc != 3)
	{
		printf("Usage: recombobulate file1 file2\n");
		return 1;
	}
	if(file1 == 0 || file2 == 0)
	{
		printf("One or both of the files could not be found.\n");
		return 1;
	}

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
