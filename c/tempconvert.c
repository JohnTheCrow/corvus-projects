#include <stdio.h>

float ftoc(float f){
	float c;
	c = (5.0 / 9.0) * (f - 32);
	return c;
}

main(){
	int f;
	for(f = 0; f <= 300; f = f + 20){
		float c = ftoc(f);
		printf("%dF = %.1fC\n", f, c);
	}
	return 0;
}
