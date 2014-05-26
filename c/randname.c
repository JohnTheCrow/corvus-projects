#include <stdio.h>
#include <stdlib.h>

/* a = 97, z = 122 */

main(){

	fname = random_in_range(97, 122);
	lname = random_in_range(97, 122);

	return 0;
}

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
