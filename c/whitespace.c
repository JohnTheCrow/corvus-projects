#include <stdio.h>

int main(){
	int c;
	int t = 0; //tabs
	int s = 0; //spaces
	int n = 0; //newline chars

	while((c = getchar()) != EOF){
		if(c == '\t'){
			++t;
		}
		else if(c == ' '){
			++s;
		}
		else if(c == '\n'){
			++n;
		}
		else{
			;
		}
	}

	printf("Total whitespace characters: %d\n", t+s+n);
	printf("Tabs: %d\n", t);
	printf("Spaces: %d\n", s);
	printf("Newlines: %d\n", n);

	return 0;
}
