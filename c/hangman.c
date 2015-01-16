#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char word[80];
char blanks[80];
char attempts[80];
int misses = 10;

int main(void)
{
	srand(time(NULL));

	getWord();
	if( (strstr(word, "-")) != NULL)
	{
		printf("Your word had a dash in it, so I'm just going to exit now");
		printf(" because frankly I don't want to deal with that. Please try");
		printf(" again.\n");
		exit(1);
	} //I am not a good programmer.

	initializeBlanks();

	while( ((strstr(blanks, "_")) != NULL) && (misses > 0))
	{
		printf("Guesses so far: %s\n", attempts);
		printf("%d miss%s left.\n", misses, (misses > 1) ? "es" : "");
		printf("%s\n", blanks);
		getGuess();
		printf("\n");
	}

	if(misses == 0)
	{
		printf("Too many misses. Game over. The word was %s.\n", word);
		return 0;
	}
	if( (strstr(blanks, "_")) == NULL)
	{
		printf("%s\n", word);
		printf("You won!\n");
	}
}

int getWord()
{

/* 4953675 is the number of chars in /usr/share/dict/linux.words minus a few.
 * The subtraction is necessary as trying to read past the file results in
 * error. */

/* TODO: We should figure out the length of /usr/share/dict/linux.words
 * programatically in case the file changes with package updates. */

	unsigned long seed = rand() % 4953675;

	FILE *fp = fopen("/usr/share/dict/linux.words", "r");
	if(fp == 0)
	{
		printf("Unable to find /usr/share/dict/linux.words.\n");
		exit(1);
	}

	// Set file position indicator _seed_ characters offset from beginning.
	fseek(fp, seed, SEEK_SET);

	while(fgetc(fp) != '\n') 
	{
		;
	} // File position indicator is now at beginning of a word.

	// Make word lowercase and remove trailing newline char.
	fgets(word, 80, fp);
	int i;
	for(i = 0; i < strlen(word); i++)
	{
		word[i] = tolower(word[i]);
	}
	word[i-1] = '\0';

	fclose(fp);
}

int initializeBlanks()
{
	int i;
	for(i = 0; i < strlen(word); i++)
	{
		strcat(blanks, "_");
	}
}

int getGuess()
{
/* Get user's guess. If that letter is in word, update blanks in the
 * appropriate position(s). If not, decrement misses. */

	char guess[2];
	int i;
	printf("What is your guess? ");
	scanf(" %s", guess);

	if(strlen(guess) > 1)
	{
		printf("\nPlease enter only one character at a time.");
		return;
	}

	if( (strstr(attempts, guess)) != NULL)
	{
		printf("\nYou already guessed that letter.");
		return;
	}

	strcat(attempts, guess);

	char c = guess[0];

	if( (strstr(word, guess)) != NULL)
	{
		for(i = 0; i < strlen(word); i++)
		{
			if(word[i] == c)
			{
				blanks[i] = word[i];
			}
		}
	}
	else
	{
		misses--;
	}
}
