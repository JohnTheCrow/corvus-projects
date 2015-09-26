#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* 
 * On the first line of the input, you will receive a number specifying how
 * many lines of input to read. After that, the input consists of some number
 * of lines of text that you will read and determine whether or not it is a
 * palindrome or not.
 *
 * The only important factor in validating palindromes is whether or not a
 * sequence of letters is the same backwards and forwards. All other types of
 * characters (spaces, punctuation, newlines, etc.) should be ignored, and
 * whether a character is lower-case or upper-case is irrelevant.
 */

/*
 * The above states that the first line of our input will be a number
 * specifying how many lines to read, but that doesn't seem to be the case when
 * looking at our sample inputs. For now I'm just going to use the literal
 * inputs given. This won't allow for palindrome testing for text read from
 * files or at the command line. Maybe I'll do that later.
 */

/* We'll do this one with pointers. */

char * fix_string(char * string);
int is_palindrome(char * string);

int main(int argc, char *argv[])
{
/* Set up our strings using pointers. */
	char * input1 = "Was it a car\nor a\ncat I saw?";
	char * input2 = "A man, a plan,\na canal, a hedgehog,\na podiatrist,\nPanama!";

	printf("%s\n%s\n",
		(is_palindrome(fix_string(input1))) ? "Palindrome" : "Not a palindrome",
		(is_palindrome(fix_string(input2))) ? "Palindrome" : "Not a palindrome");

	return 0;
}

/*
 * Take a string and change all capitals to lowercase and remove all spaces
 * and punctuation. Return a pointer to the fixed string.
 */
char * fix_string(char * string)
{
	int string_length = strlen(string);
	char * fixed_string = (char *)malloc(string_length);
	int i = 0, j = 0;

	for(i = 0; i < string_length; i++)
	{
		if(isupper(string[i]))
		{
			fixed_string[j] = tolower(string[i]);
			j++;
		}
		else if(islower(string[i]))
		{
			fixed_string[j] = string[i];
			j++;
		}
	}
	fixed_string[j] = '\0';

	return fixed_string;
}

/* Check to see if a given string is a palindrome. */
int is_palindrome(char * string)
{
	int start = 0;
	int end = strlen(string) - 1; // 0 indexes

	while(start < end)
	{
		if(string[start] != string[end])
			return 0;
		else
		{
			start++;
			end--;
		}
	}

	return 1;
}
