#include <stdio.h>

int main(){
	int c, nl = 0;

	while((c = getchar()) != EOF){
		if(c == '\n'){
			++nl;
		}
	}

	if(nl == 0){
		printf("Try again, asshole.\n");
	}
	else if(nl == 1){
		printf("There is %d new line character.\n", nl);
	}
	else{
		printf("There are %d new line characters.\n", nl);
	}

	return 0;
}
