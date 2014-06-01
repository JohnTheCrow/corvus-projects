#include <stdio.h>
#define	LIMIT	80

main(){
	char s[LIMIT];
	int i, c;

	for(i = 0; i < LIMIT && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	while(i >= 0){
		printf("%c", s[i]);
		--i;
	}
	printf("\n");
	return 0;
}
