#include <stdio.h>
#define MAX_SIZE 6

void printStr(const char str[]);
//void writeToStr (char str[], int size);

int main() {
	char type[MAX_SIZE];
	
	printf("What type will you write? [int/float] ");
	scanf("%s", type);
	
	printStr(type);
	
}

//void writeToStr (char str[], int size) {
//	char c;
//	for (int i=0; i<size-1; i++) {
//		if ((c = getchar()) != '\n') {
//			str[i] = c;
//		} else break;
//	}
//	printf("out of write\n");
//}


void printStr(const char str[]) {
	int i;
	for(i=0;;i++) {
		if(str[i] == '\0') break;
		printf("%c", str[i]);
	}
	printf('\n');
	printf("out of print");
}


