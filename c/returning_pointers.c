/* Sams Teach Yourself C Programming in One Hour a Day 7th Edition
 * Lesson 10 exercise 6 */

#include <stdio.h>
#include <stdlib.h>

char * longer(char * string1, char * string2);

int main(int argc, char **argv)
{
	char string1[80], string2[80];

	printf("Enter a string: ");
	fgets(string1, 80, stdin);
	printf("Enter another string: ");
	fgets(string2, 80, stdin);

	printf("\nThe longer string was:\n%s\n", longer(string1, string2));

	return 0;
}

/* Return the pointer to the longer of two strings. */
char * longer(char * string1, char * string2)
{
	int count1 = sizeof(string1) / sizeof(char);
	int count2 = sizeof(string2) / sizeof(char);

	if(count1 > count2)
	{
		return string1;
	}
	else
	{
		return string2;
	}
}
