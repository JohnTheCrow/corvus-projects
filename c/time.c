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

/* Print the time in a human friendly format. ctime_r() takes a time_t pointer
 * and asctime_r() takes a struct tm pointer. Both return a newline and null
 * terminated string that will be 26 bytes. */

	char *buf1 = (char *)malloc(26);
	char *buf2 = (char *)malloc(26);
	ctime_r(&t, buf1);
	asctime_r(&t_s, buf2);

	printf("%s%s", buf1, buf2);

	return 0;
}
