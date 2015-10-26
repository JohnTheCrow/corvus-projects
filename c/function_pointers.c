#include <stdio.h>
#include <stdlib.h>

struct number_ops {
	int (*one)(int i);
	int (*two)(int i);
	int (*three)(int i);
};

int my_one(int i);
int my_two(int i);
int my_three(int i);

int main(int argc, char *argv[])
{
	struct number_ops my_number_ops = {
		.one	= my_one,
		.two	= my_two,
		.three	= my_three
	};

	int x = 0;

	while(x < 1 || x > 3)
	{
		printf("Enter a number 1-3: ");
		scanf("%d", &x);
	}

	switch(x)
	{
		case 1: my_number_ops.one(x); break;
		case 2: my_number_ops.two(x); break;
		case 3: my_number_ops.three(x); break;
	}

	return 0;
}

int my_one(int i)
{
	printf("%d\n", i);
}

int my_two(int i)
{
	printf("%d\n", i);
}

int my_three(int i)
{
	printf("%d\n", i);
}
