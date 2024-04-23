#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int n;
	
	printf("n? ");
	scanf("%d", &n);
	
	for (int i=2; i<n; i++) {
		if (n/i && (n%i==0)) {
			printf("Not Simple!");
			return 0;
		}
	}
	printf("Simple!");

	return 0;
}
