#include <stdio.h>
#define MAX_SIZE 6

void printStr(const char str[]);

int main() {
	char type[MAX_SIZE];
	
	printf("What type will you write? [int/float] ");
	
	for (int i=0; i<MAX_SIZE; i++) {
		if ((type[i] = getchar()) == '\0') break;
	}



	
}


void printStr(const char str[]) {
	int i;
	for(i=0;;i++) {
		if(str[i] == '\0') break;
		printf("%c", str[i]);
	}
}


