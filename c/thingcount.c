#include <stdio.h>

main(){
	int c, wcount, ocount, i;
	int dcount[10];
	wcount = ocount = i = 0;

	for(i = 0; i < 10; ++i){
		dcount[i] = 0;
	}

	while((c = getchar()) != EOF){
		if(c >= '0' && c <= '9'){
			++dcount[c-'0'];
		}
		else if(c == ' ' || c == '\n' || c == '\t'){
			++wcount;
		}
		else{
			++ocount;
		}
	}

	printf("Number of:\n");
	printf("0  1  2  3  4  5  6  7  8  9\tWhitespace\tOther\n");
	for(i = 0; i < 10; ++i){
		printf("%d  ", dcount[i]);
	}
	printf("\t%d\t\t%d\n", wcount, ocount);

	return 0;
}
