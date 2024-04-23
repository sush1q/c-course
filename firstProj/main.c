#include <stdio.h>

int main()
{
	int i=0, n=0, sum=0, zeroCount=0, prev=0, maxDublicateCount=0, curDublicateCount=1, isIncreasing=1, min, max, cur;

	printf("How many numbers will you write? ");
	scanf("%d", &n);	
	
	while (i != n) {
		
		printf("number? ");
		scanf("%d", &cur);
		
		if (i == 0) {
			min = cur;
			max = cur;
		}
		
//		1 - count sum
		sum += cur;

//		2 - zero count
		if (cur == 0) zeroCount++;

//		3 - min & max
		if (min > cur) min = cur;
		if (max < cur) max = cur;

//		4 - increase
		if (isIncreasing) {
			if (prev >= cur && i != 0) {
				isIncreasing = 0;
			}
		}

//		5 - dublicate
		if (prev == cur) curDublicateCount++;
		else curDublicateCount=1;
		if (maxDublicateCount<curDublicateCount) maxDublicateCount=curDublicateCount;

		prev = cur;
		i++;
	}
	
	printf("sum: %d\n", sum);
	printf("zero count: %d\n", zeroCount);
	printf("min: %d ; max: %d\n", min, max);
	printf("is increasing seq: %d\n", isIncreasing);
	printf("dublicate count: %d\n", maxDublicateCount);
	
}

