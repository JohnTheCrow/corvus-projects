#include <stdio.h>
#include <stdlib.h>

/* Evaluates the address of MEMBER from the starting address of STRUCT_TYPE.
 * With a starting address of 0, we get the offset in bytes of MEMBER into
 * STRUCT_TYPE. Note that the address is not dereferenced.
 */

#define offsetof(STRUCT_TYPE, MEMBER) ((long)&((STRUCT_TYPE *)0)->MEMBER)

struct my_struct {
	int var_int;
	float var_float;
	char var_char;
};

int main(int argc, char *argv[])
{
	long offset = offsetof(struct my_struct, var_char);
	printf("%ld\n", offset);

	return 0;
}
