#include <stdio.h>
#include <stdlib.h>


int main() {
	int n, prev1=0, prev2=0;
	printf("n? ");
	scanf("%d", &n);
	
	for (int i=1; i<=n; i++) {
		int cur;
		
		if (i==1) prev2 = i;
		
		cur = prev1+prev2;
		prev1 = prev2;
		prev2 = cur;
		printf("%d, ", cur);
	}

	return 0;
}
