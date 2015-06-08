#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printvalues(void);

struct data{
	char value[20];
	struct data * next; 
};

struct data * head = NULL;
struct data * current = NULL;
struct data * new = NULL;
struct data * marker = NULL;

int main(int argc, char *argv[])
{

/* Create a series of new elements in a linked list, putting each one at the
 * beginning as its created. */
/* TODO: If the user enters 20 or more characters bad things happen. I thought
 * fgets() was supposed to prevent this sort of thing. What's going on? */
	int i;
	for(i = 0; i < 5; i++)
	{
		new = (struct data *)malloc(sizeof(struct data));
		if(!new)
		{
			printf("Error allocating memory.\n");
			return 1;
		}
		printf("Enter a value: ");
		fgets(new->value, 20, stdin);
		new->value[strcspn(new->value, "\n")] = '\0';
		new->next = head;
		head = new;
	}

	printvalues();

/* Create a new element at the end of the list. */
	current = head;
	while(current->next)
		current = current->next;
	new = (struct data *)malloc(sizeof(struct data));
	if(!new)
	{
		printf("Error allocating memory.\n");
		return 1;
	}
	current->next = new;
	new->next = NULL;
	printf("Enter a value: ");
	fgets(new->value, 20, stdin);
	new->value[strcspn(new->value, "\n")] = '\0';

	printvalues();

/* Create new element and insert it into the middle of the list. */
	current = head;
/* This for loop only executes once so it's not strictly necessary. However
 * I'm leaving it here to make it easy to change where the new element would
 * go. */
	for(i = 0; i < 1; i++) // Places new element in 3rd position
		current = current->next;
	marker = current; // Could use "current" but "marker" is more descriptive
	new = (struct data *)malloc(sizeof(struct data));
	if(!new)
	{
		printf("Error allocating memory.\n");
		return 1;
	}
	new->next = marker->next;
	marker->next = new;
	printf("Enter a value: ");
	fgets(new->value, 20, stdin);
	new->value[strcspn(new->value, "\n")] = '\0';

	printvalues();

	return 0;
}

void printvalues(void)
{
	printf("You entered the values: ");
	current = head;
	while(current->value)
	{
		printf("%s ", current->value);
		current = current->next;
	}
	printf("\n");
}
