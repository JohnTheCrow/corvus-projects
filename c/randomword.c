#include <stdio.h>

/* Pull a random line out of /usr/share/dict/linux.words and print it to the
 * terminal. */

int main(void)
{

/* 4953675 is the number of chars in /usr/share/dict/linux.words minus a few.
 * The subtraction is necessary as trying to read past the file results in
 * funkiness. */

	srand(time(NULL));
	unsigned long seed = rand() % 4953675;

	FILE *fp = fopen("/usr/share/dict/linux.words", "r");
	if(fp == 0)
	{
		printf("Unable to find file.\n");
		exit(1);
	}

	fseek(fp, seed, SEEK_SET);

	while(fgetc(fp) != '\n') 
	{
		;
	} //File pointer is now at beginning of a word

	char word[80];
	fgets(word, 80, fp);

	printf("%s", word);

	fclose(fp);
}
