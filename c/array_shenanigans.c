#include <stdio.h>
#include <stdlib.h>

#define HIGH_LIMIT 2147483647 // max for signed int
#define LOW_LIMIT 1
#define ARRAY_SIZE 5

void getNums();
void getValues();

int array[ARRAY_SIZE] = {0};
int low = HIGH_LIMIT;
int high = LOW_LIMIT;

int main(int argc, char **argv)
{
	getNums();
	getValues();

	printf("The lowest value you entered is %d.\n", low);
	printf("The highest value you entered is %d.\n", high);

	return 0;
}

void getNums()
{
	int number, i;

	for(i = 0; i < ARRAY_SIZE; i++)
	{
		printf("Enter a number between %d and %d, 0 to quit: ",
               LOW_LIMIT, HIGH_LIMIT);
		scanf("%d", &number);

		if(number == 0 && i == 0)
		{
			printf("Please enter at least one number in range.\n");
			i--;
			continue;
		}
		if(number == 0)
		{
			return;
		}
		if(number < LOW_LIMIT || number > HIGH_LIMIT)
		{
			printf("Number not in range.\n");
			i--;
			continue;
		}

		array[i] = number;
	}
}

void getValues()
{
	int i;
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		if(array[i] < low && array[i] != 0)
		{
			low = array[i];
		}
		if(array[i] > high && array[i] != 0)
		{
			high = array[i];
		}
	}
}
