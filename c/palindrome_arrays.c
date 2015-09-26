#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

/* We'll do this one with arrays. */

int main(int argc, char *argv[])
{
/* Set up our strings using arrays. */
	char input1[] = "Was it a car\nor a\ncat I saw?";
	char input2[] = "A man, a plan,\na canal, a hedgehog,\na podiatrist,\nPanama!";


/* We don't care about punctuation, spaces, or case sensativity so let's
 * convert our strings to long lines of only lower-case letters. */

/* First, let's get the number of elements (characters) in the array so we can
 * later use that as a counter for a loop. */
	int size_input1 = sizeof(input1) / sizeof(char);
	int size_input2 = sizeof(input2) / sizeof(char);
/* Create some new arrays to hold our fixed strings. */
	char fixedinput1[size_input1];
	char fixedinput2[size_input2];
	int i, j = 0;

/* Iterate through each character in the input. Take capital letters and
 * convert them to lowercase and put them in the new array. Move lowercase
 * letters directly over. Ignore punctuation and spaces. */

	for(i = 0; i < size_input1; i++)
	{
		if(isupper(input1[i]))
		{
			fixedinput1[j] = tolower(input1[i]);
			j++;
		}
		else if(islower(input1[i]))
		{
			fixedinput1[j] = input1[i];
			j++;
		}
	}
	fixedinput1[j] = '\0'; // "Cap off" the new array

	j = 0;

	for(i = 0; i < size_input2; i++)
	{
		if(isupper(input2[i]))
		{
			fixedinput2[j] = tolower(input2[i]);
			j++;
		}
		else if(islower(input2[i]))
		{
			fixedinput2[j] = input2[i];
			j++;
		}
	}
	fixedinput2[j] = '\0'; // "Cap off" the new array

/* Get the size of the fixed inputs NOT including the NULL terminator, because
 * we don't want to use that for testing if the string is a palindrome. We
 * can't just take the size of the array this time because we know our array is
 * larger than our string at this point, so we count how many chars there are
 * until we reach \0. */

	int size_fixed1 = 0; 
	int size_fixed2 = 0;

	while(fixedinput1[size_fixed1] != '\0')
		size_fixed1++;

	while(fixedinput2[size_fixed2] != '\0')
		size_fixed2++;

/* Our size_fixedX variables now equal the size of our strings not including
 * the NULL terminator, but since the arrays are 0 indexed we'll need to
 * decrement them both by 1 for the next part. */

	size_fixed1--;
	size_fixed2--;
	i = 0;
	int palindrome = 1;

/* i will represent the start of our string and size_fixedX will represent the
 * end. We'll loop, comparing i to size_fixedX then increment i and decrement
 * sized_fixedX. If we ever run into a mismatch, it's not a palindrome. */

	while(i < size_fixed1) // Only need to check up to the middle
	{
//		printf("Comparing %c and %c\n", fixedinput1[i], fixedinput1[size_fixed1]);

		if(fixedinput1[i] != fixedinput1[size_fixed1])
		{
			palindrome = 0;
			break;
		}
		else
		{
			i++;
			size_fixed1--;
		}
	}
	if(palindrome)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	palindrome = 1;
	i = 0;

	while(i < size_fixed2)
	{
//		printf("Comparing %c and %c\n", fixedinput2[i], fixedinput2[size_fixed2]);
		if(fixedinput2[i] != fixedinput2[size_fixed2])
		{
			palindrome = 0;
			break;
		}
		else
		{
			i++;
			size_fixed2--;
		}
	}
	if(palindrome)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
} // Ugly, but it works
