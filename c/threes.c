#include <stdio.h>
#include <stdlib.h>

/*
 * The input is a single number: the number at which the game starts. Write a
 * program that plays the Threes game, and outputs a valid sequence of steps you
 * need to take to get to 1. Each step should be output as the number you start
 * at, followed by either -1 or 1 (if you are adding/subtracting 1 before
 * dividing), or 0 (if you are just dividing). The last line should simply be 1.
 */

// https://www.reddit.com/r/dailyprogrammer/comments/3r7wxz/20151102_challenge_239_easy_a_game_of_threes/

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("Usage: threes <number>\n");
		return 1;
	}

	int number = atoi(argv[1]);

	if(number == 0) {
		printf("You entered \"0\" or some string that evaluated to it. "
			"This has caused a rip in the fabric of space time. "
			"I hope you're proud of yourself.\n");
		return 0;
	}

	while(number != 1)
	{
		printf("%d ", number);

		if(number % 3 == 0) {
			printf("0\n");
		}

		else if(number % 3 == 1) {
			printf("-1\n");
			number --;
		}

		else { // number % 3 must equal 2
			printf("1\n");
			number++;
		}

		number /= 3;
	}

	printf("%d\n", number);
	return 0;
}
