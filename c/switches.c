#include <stdio.h>

/* Convert real new line and tab characters into their escape sequences:
 * \t - tab
 * \n - new line */

/* How do I stop '\n' from appearing prematurely when I press enter? */

main(){
	char newline[] = "\\n";
	char tab[]     = "\\t";
	int c;

	while((c = getchar()) != '\0'){
		switch(c){
			case '\n':
				printf("%s", newline);
				break;
			case '\t':
				printf("%s", tab);
				break;
			default:
				printf("%c", c);
		}
	}

	printf("\n");

	return 0;
}
