#include <stdio.h>
#include <stdlib.h>

/* 100 doors start out opened. Iterate through the doors. On the 1st iteration,
 * toggle the state (open/closed) of every door. On the 2nd iteration, toggle
 * the state of every 2nd door. Continue until on the 100th iteration where you
 * toggle the state of the 100th door. What's the state of the doors? */

int main(int argc, char **argv)
{
	int doors[100] = {0};
	int iteration, i;

	for(iteration = 1; iteration <= 100; iteration++)
	{
		i = iteration - 1;
		while(i <= 99)
		{
			doors[i] = doors[i] ^ 1;
			i += iteration;
		}
	}

	for(i = 0; i <= 99; i++)
		printf("Door %i is %s.\n", i + 1, (doors[i] == 0) ? "closed" : "open"); 

	return 0;
}
