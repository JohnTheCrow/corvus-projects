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
	initializeBlanks();

/* Still blanks in word. */
	while( ((strstr(blanks, "_")) != NULL) && (misses > 0))
	{
		printf("Guesses so far: %s\n", attempts);
		printf("%d misses left.\n", misses);
		getGuess();
		printf("%s\n\n", blanks);
	}

	if(misses == 0)
	{
		printf("Too many misses. Game over. The word was %s.\n", word);
		exit(1);
	}
	if( (strstr(blanks, "_")) == NULL) //There are no blanks in word.
	{
		printf("You won!\n");
	}
}

int getWord()
{

/* 4953675 is the number of chars in /usr/share/dict/linux.words minus a few.
 * The subtraction is necessary as trying to read past the file results in
 * error. */

	unsigned long seed = rand() % 4953675;

	FILE *fp = fopen("/usr/share/dict/linux.words", "r");
	if(fp == 0)
	{
		printf("Unable to find /usr/share/dict/linux.words.\n");
		exit(1);
	}

	fseek(fp, seed, SEEK_SET);

	while(fgetc(fp) != '\n') 
	{
		;
	} //File pointer is now at beginning of a word.

	fgets(word, 80, fp);
	int i;
	for(i = 0; i < strlen(word); i++)
	{
		word[i] = tolower(word[i]);
	}
	word[i-1] = '\0'; //word now no longer contains a newline character.

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
		printf("Please enter only one character at a time.\n");
		return;
	}

	if( (strstr(attempts, guess)) != NULL) //Letter already guessed.
	{
		printf("You already guessed that letter.\n");
		return;
	}

	strcat(attempts, guess);

	char c = guess[0];

	if( (strstr(word, guess)) != NULL) //If guess is in word.
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
