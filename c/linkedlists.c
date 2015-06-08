#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printnames(void);

struct person{
	char name[20];
	struct person * next; 
};

struct person * head = NULL;
struct person * current = NULL;
struct person * new = NULL;
struct person * marker = NULL;

int main(int argc, char *argv[])
{

/* Create a series of new elements in a linked list, putting each one at the
 * beginning as its created. */
/* TODO: If the user enters 20 or more characters bad things happen. I thought
 * fgets() was supposed to prevent this sort of thing. What's going on? */
	int i;
	for(i = 0; i < 5; i++)
	{
		new = (struct person *)malloc(sizeof(struct person));
		if(!new)
		{
			printf("Error allocating memory.\n");
			return 1;
		}
		printf("Enter a value: ");
		fgets(new->name, 20, stdin);
		new->name[strcspn(new->name, "\n")] = '\0';
		new->next = head;
		head = new;
	}

	printnames();

/* Create a new element at the end of the list. */
	current = head;
	while(current->next)
		current = current->next;
	new = (struct person *)malloc(sizeof(struct person));
	if(!new)
	{
		printf("Error allocating memory.\n");
		return 1;
	}
	current->next = new;
	new->next = NULL;
	printf("Enter a value: ");
	fgets(new->name, 20, stdin);
	new->name[strcspn(new->name, "\n")] = '\0';

	printnames();

/* Create new element and insert it into the middle of the list. */
//TODO: Why is this placing the element 4th in the list?
	current = head;
	for(i = 0; i < 2; i++) // Because I want my new element placed 3rd
		current = current->next;
	marker = current; // Not necessary but "marker" is more descriptive
	new = (struct person *)malloc(sizeof(struct person));
	if(!new)
	{
		printf("Error allocating memory.\n");
		return 1;
	}
	new->next = marker->next;
	marker->next = new;
	printf("Enter a value: ");
	fgets(new->name, 20, stdin);
	new->name[strcspn(new->name, "\n")] = '\0';

	printnames();

	return 0;
}

void printnames(void)
{
	printf("You entered the values: ");
	current = head;
	while(current->name)
	{
		printf("%s ", current->name);
		current = current->next;
	}
	printf("\n");
}
