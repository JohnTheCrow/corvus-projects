#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, k;

	printf("Enter a number: ");
	scanf(" %d", &i);

	printf("%d in binary is ", i);

	for(j = 31; j >= 0; j--)
	{
		k = i >> j;

		if(k & 1)
			printf("1");
		else
			printf("0");
	}

	printf("\n");
}
