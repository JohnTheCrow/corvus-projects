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
 * OK this time we're gonna see if we wanna use one of the given inputs, read
 * some input from a file, or read some input from the command line.
 */

char * fix_string(char * string);
int is_palindrome(char * string);
int sample(void);
int from_file(void);
int from_cmdline(void);

int main(int argc, char *argv[])
{
	printf("Do you want to check to see if something is a palindrome using "
		"text from a file, text entered at the command line, or from a sample "
		"input?\n"
		"1) From a file\n"
		"2) From the command line\n"
		"3) Sample input\n");


	int choice = 0;
	while(choice < 1 || choice > 3)
	{
		printf("Enter (1-3): ");
		scanf("%d", &choice);
	}

	switch(choice)
	{
		case 1:
			from_file();
			break;
		case 2:
			from_cmdline();
			break;
		case 3:
			sample();
			break;
	}

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

/* Ask the user which of these pre-defined strings they want to test against. */
int sample(void)
{
/* Set up our strings using pointers. */
	char * input1 = "Was it a car\nor a\ncat I saw?";
	char * input2 = "A man, a plan,\na canal, a hedgehog,\na podiatrist,\nPanama!";

	printf("Sample 1:\n\n%s\n\nSample 2:\n\n%s\n\nUse sample 1 or 2?\n",
		input1, input2);

	int choice = 0;

	while(choice < 1 || choice > 2)
	{
		printf("Enter (1 or 2): ");
		scanf("%d", &choice);
	}

	if(choice == 1)
		printf("%s\n", (is_palindrome(fix_string(input1))) ? "Palindrome" : "Not a palindrome");
	else if(choice == 2)
		printf("%s\n", (is_palindrome(fix_string(input2))) ? "Palindrome" : "Not a palindrome");
	else
		return 1; // Something went very wrong

	return 0;
}

/*
 * Ask for a file. First line of the file should be a number indicating how
 * many lines of text after that number we'll read for our test.
 */
int from_file(void)
{
	char * filename = (char *)malloc(sizeof(char) * 255);

/*
 * Get a filename, open that file, explicitly set our pointer to the beginning
 * of the file.
 */
	while(getchar() != '\n');
	printf("Enter a file to use: ");
	fgets(filename, 255, stdin);
/* filename will contain a trailing '\n', so... */
	filename[strcspn(filename, "\n")] = '\0';
	FILE * fp = fopen(filename, "r");
	if(!fp)
	{
		printf("Unable to open that file.\n");
		return 1;
	}
	fseek(fp, 0, SEEK_SET);

/* Get how many lines we'll be reading. */
	char * lines = (char *)malloc(sizeof(int));
	fgets(lines, 9, fp);
	int nr_lines = atoi(lines);

/*
 * Store that number of lines in a buffer. Our file pointer should now be on
 * the second line. I'm not sure how to store an undetermined amount of data
 * in a buffer. 8 MiB will have to be enough for now.
 */
	char * buffer = (char *)malloc(sizeof(char) * 8192);
	char * input = (char *)malloc(sizeof(char) * 8192);
	int i;

	for(i = 1; i <= nr_lines; i++)
	{
		fgets(buffer, 8192, fp);
		strcat(input, buffer);
	}

	printf("%s\n", (is_palindrome(fix_string(input))) ? "Palindrome" : "Not a palindrome");

	fclose(fp);

	return 0;
}

/* Read whatever a user types in at the command line and test against it. */
int from_cmdline(void)
{
/* Store at most 128 characters. */
	char * input = (char *)malloc(sizeof(char) * 128);

	while(getchar() != '\n');
	printf("Enter a string: ");
	fgets(input, 128, stdin);

/*
 * OK, that last part was a _bitch_. Without that while loop, the input string
 * wound up containing nothing but a single '\n', which is where fgets() will
 * stop reading. This resulted in the user never getting to enter anything and
 * "Palindrom" always printing to the screen (I guess a single character is a
 * palindrome, right?). Googled around and tried
 *
 * fflush(stdin)
 * - and -
 * fseek(stdin, 0, SEEK_END)
 *
 * to no avail before stumbling upon the while loop. I get that we're clearing
 * the input buffer but I'm still not sure why we need to or why the other two
 * things didn't work. */

	printf("%s\n", (is_palindrome(fix_string(input))) ? "Palindrome" : "Not a palindrome");

	return 0;
}
