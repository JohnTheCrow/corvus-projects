#include <stdio.h>
#include <string.h>

/* Take line 1 in files 1 and 2 and print them on one line. Do same for all
 * lines of file. Files must have an equal number of lines. Currently uses a
 * space for the delimiter. */

//TODO: Allow for more than two files to be recombobulated
//TODO: Allow for choice of delimiter between same-line strings

int main(int argc, char **argv)
{
	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");
	char buffer1[80], buffer2[80], ch;
	int nr_lines1 = 0; int nr_lines2 = 0;

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

	while(!feof(file1))
	{
		ch = fgetc(file1);
		if(ch == '\n')
			nr_lines1++;
	}
	while(!feof(file2))
	{
		ch = fgetc(file2);
		if(ch == '\n')
			nr_lines2++;
	}

	if(nr_lines1 != nr_lines2)
	{
		printf("The files do not have an equal number of lines.\n");
		return 1;
	}

	fseek(file1, 0, SEEK_SET);
	fseek(file2, 0, SEEK_SET);

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
