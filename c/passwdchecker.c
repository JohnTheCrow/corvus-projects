#include <stdio.h> //Includes printf()
#include <stdlib.h>
#include <string.h> //Includes strlen()
#include <ctype.h> //Includes isalpha(), isdigit(), etc.

/* Take a password and check to see if it has at least one uppercase, one
 * lowercase, and one digit character. */

void main()
{
	char password[9];
	int i, hasLower, hasUpper, hasDigit;
	i = hasLower = hasUpper, hasDigit = 0;

	printf("Enter a password with at least one uppercase, one lowercase,");
	printf(" and one digit character. Max 8 characters.\n");
	printf("Enter password: ");
	scanf(" %s", password);

	for(i = 0; i < strlen(password); i++)
	{
		if( islower(password[i]) )
		{
			hasLower = 1;
			continue;
		}
		if( isupper(password[i]) )
		{
			hasUpper = 1;
			continue;
		}
		if( isdigit(password[i]) )
		{
			hasDigit = 1;
			continue;
		}
	}

	if( hasLower && hasUpper && hasDigit )
	{
		printf("Your password meets the requirements.\n");
	}
	else
	{
		printf("Your password does not meet the requirements.\n");
	}

}
