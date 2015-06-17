#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char word[80];
char blanks[80];
char attempts[80];
int guesses = 10;

int main(void)
{
	srand(time(NULL));

dash:
	getWord();
	if( (strstr(word, "-")) != NULL)
	{
		goto dash;
	} 

	initializeBlanks();

	while( ((strstr(blanks, "_")) != NULL) && (guesses > 0))
	{
		printf("Guesses so far: %s\n", attempts);
		printf("%d guess%s left.\n", guesses, (guesses > 1) ? "es" : "");
		printf("%s\n", blanks);
		getGuess();
		printf("\n");
	}

	if(guesses == 0)
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

/* Open the words file, determine its length, and generate a random seed. */
	FILE *fp = fopen("/usr/share/dict/linux.words", "r");
	if(fp == 0)
	{
		printf("Unable to find /usr/share/dict/linux.words.\n");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	long base = ftell(fp) - 50;
	unsigned long seed = rand() % base;


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
 * appropriate position(s). If not, decrement guesses. */

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
		guesses--;
	}
}
