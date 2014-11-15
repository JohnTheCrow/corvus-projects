#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	srand(time(NULL));

	int roll = (rand() % 20) + 1;

	printf("Determining your fate...\n\n");
	sleep(2);

	switch(roll)
	{
		case 1:
			printf("It is certain.\n");
			break;
		case 2:
			printf("It is decidedly so.\n");
			break;
		case 3:
			printf("Without a doubt.\n");
			break;
		case 4:
			printf("Yes definitely.\n");
			break;
		case 5:
			printf("You may rely on it.\n");
			break;
		case 6:
			printf("As I see it, yes.\n");
			break;
		case 7:
			printf("Most likely.\n");
			break;
		case 8:
			printf("Outlook good.\n");
			break;
		case 9:
			printf("Yes.\n");
			break;
		case 10:
			printf("Signs point to yes.\n");
			break;
		case 11:
			printf("Reply hazy try again.\n");
			break;
		case 12:
			printf("Ask again later.\n");
			break;
		case 13:
			printf("Better not tell you now.\n");
			break;
		case 14:
			printf("Cannot predict now.\n");
			break;
		case 15:
			printf("Concentrate and ask again.\n");
			break;
		case 16:
			printf("Don't count on it.\n");
			break;
		case 17:
			printf("My reply is no.\n");
			break;
		case 18:
			printf("My sources say no.\n");
			break;
		case 19:
			printf("Outlook not so good.\n");
			break;
		case 20:
			printf("Very doubtful.\n");
			break;
		default:
			printf("The random number generator is broken.\n");
			break;
	}
}
