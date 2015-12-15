#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
/* Stores epoch in a given time_t variable. */
	time_t t;
	time(&t);

/* Makes a tm struct out of epoch time and saves it in the given struct.
 * See 'man 3 localtime' for details on the struct. */
	struct tm t_s;
	localtime_r(&t, &t_s);

	printf("Epoch: %ld\nDate: %d/%d/%d %d:%d:%.2d\n",
		t, t_s.tm_mday, t_s.tm_mon + 1, t_s.tm_year + 1900, t_s.tm_hour,
		t_s.tm_min, t_s.tm_sec);

/* Converts a tm struct to epoch. */
	time_t t2 = mktime(&t_s);

	return 0;
}
