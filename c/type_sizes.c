#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("A char is         %d bytes.\n", sizeof(char));
	printf("An int is         %d bytes.\n", sizeof(int));
	printf("A long is         %d bytes.\n", sizeof(long));
	printf("A long long is    %d bytes.\n", sizeof(long long));
	printf("A float is        %d bytes.\n", sizeof(float));
	printf("A double is       %d bytes.\n", sizeof(double));
	printf("A long double is %d bytes.\n", sizeof(long double));
}
