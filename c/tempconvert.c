#include <stdio.h>

int ftoc(int f){
	int c;
	c = (5.0 / 9.0) * (f - 32);
	return c;
}

main(){
	int f;
	for(f = 0; f <= 300; f = f + 20){
		int c = ftoc(f);
		printf("%dF = %dC\n", f, c);
	}
	return 0;
}
