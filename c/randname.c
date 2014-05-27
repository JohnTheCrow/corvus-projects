#include <stdio.h>
#include <stdlib.h>

main(){

	srand(time(NULL));

	int fname, lname;

	fname = random_in_range(97, 122);
	lname = random_in_range(97, 122);

	if(fname == 97){printf("Black");}
	if(fname == 98){printf("White");}
	if(fname == 99){printf("Gold");}
	if(fname == 100){printf("Dick");}
	if(fname == 101){printf("Lemmy");}
	if(fname == 102){printf("Bruce");}
	if(fname == 103){printf("Demonsthenes");}
	if(fname == 104){printf("Sirius");}
	if(fname == 105){printf("Heisenberg");}
	if(fname == 106){printf("Shadow");}
	if(fname == 107){printf("Laughing");}
	if(fname == 108){printf("Smirking");}
	if(fname == 109){printf("Dying");}
	if(fname == 110){printf("Goth");}
	if(fname == 111){printf("Darth");}
	if(fname == 112){printf("Emperor");}
	if(fname == 113){printf("Beep");}
	if(fname == 114){printf("Crusty");}
	if(fname == 115){printf("Sideshow");}
	if(fname == 116){printf("Nervous");}
	if(fname == 117){printf("Splatter");}
	if(fname == 118){printf("Dexter");}
	if(fname == 119){printf("Scarface");}
	if(fname == 120){printf("Ender");}
	if(fname == 121){printf("Achilles");}
	if(fname == 122){printf("Locke");}

	printf(" ");

	if(lname == 97){printf("Graff");}
	if(lname == 98){printf("Moriarty");}
	if(lname == 99){printf("Liquid");}
	if(lname == 100){printf("Genius");}
	if(lname == 101){printf("Balrog");}
	if(lname == 102){printf("Vega");}
	if(lname == 103){printf("Splinter");}
	if(lname == 104){printf("Fuerte");}
	if(lname == 105){printf("Formic");}
	if(lname == 106){printf("Thrall");}
	if(lname == 107){printf("Rags");}
	if(lname == 108){printf("Jager");}
	if(lname == 109){printf("Fiddich");}
	if(lname == 110){printf("Reynolds");}
	if(lname == 111){printf("Sara");}
	if(lname == 112){printf("Bane");}
	if(lname == 113){printf("Organa");}
	if(lname == 114){printf("Solo");}
	if(lname == 115){printf("Fry");}
	if(lname == 116){printf("Bender");}
	if(lname == 117){printf("Wash");}
	if(lname == 118){printf("Fey");}
	if(lname == 119){printf("McNulty");}
	if(lname == 120){printf("Dagger");}
	if(lname == 121){printf("Tribal");}
	if(lname == 122){printf("Strife");}

	printf("\n");

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
