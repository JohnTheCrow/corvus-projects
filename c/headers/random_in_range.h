#include <stdio.h>
#include <stdlib.h>

/* Always put 'srand(time(NULL));' at the beginning of main()
 * when calling this function. Without it, your program
 * will return the same number each time it's run.  */

int random_in_range(unsigned int min, unsigned int max){

  int base_random = rand();

  if(RAND_MAX == base_random){
		return random_in_range(min, max);
	}

  int range       = max - min,
      remainder   = RAND_MAX % range,
      bucket      = RAND_MAX / range;

  if(base_random < RAND_MAX - remainder){
    return min + base_random/bucket;
 		}
	else{
    return random_in_range(min, max);
  }
}
