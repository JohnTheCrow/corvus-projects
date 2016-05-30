#include <stdio.h>
#include <stdlib.h>

/* Evaluates the address of MEMBER from the starting address of STRUCT_TYPE.
 * With a starting address of 0, we get the offset in bytes of MEMBER into
 * STRUCT_TYPE. Note that the address is not dereferenced.
 */

#define offsetof(STRUCT_TYPE, MEMBER) ((long)&((STRUCT_TYPE *)0)->MEMBER)

/* Returns a pointer to the base of a struct given a pointer (ptr) to a
 * member, the type of struct, and name of the member. typeof() is apparently
 * built into gcc and returns the data type of the argument passed to it.
 *
 * The first line of the macro is creating a pointer of type from the passed
 * in ptr. The second line is taking that pointer and subtracting the offset
 * of the member into the struct. The result is a pointer to the base of the
 * struct.
 */

#define containerof(ptr, type, member) ({			\
	const typeof(((type *)0)->member) *__mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member));})

struct my_struct {
	int   var_int;   // sizeof == 4
	float var_float; // sizeof == 4
	char  var_char;  // offset == 8
};

int main(int argc, char *argv[])
{
	/* Demonstrate offsetof() by finding the offset of var_char within
 	 * my_struct. */
	long offset = offsetof(struct my_struct, var_char);
	printf("%ld\n", offset);

	/* Demonstrate containerof() by malloc'ing a my_struct "ms",
	 * initializing a pointer to its var_char member, and initializing a
	 * new pointer to  ms via the pointer to var_char. */
	struct my_struct *ms = (struct my_struct *)malloc(sizeof(struct my_struct));
	char *cptr = &ms->var_char;
	struct my_struct *ms2 = containerof(cptr, struct my_struct, var_char);
	printf("%p\n%p\n", ms2, cptr);

	return 0;
}
