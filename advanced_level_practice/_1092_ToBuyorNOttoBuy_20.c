/*
 * * 利用 ASCII 数组对应珠子的数目
 */

#include <stdio.h>

int main(void)
{
	int beads[128] = {0};
	char ch;
	int i, more = 0, less = 0;
	while ((ch = getchar()) != '\n') {
		beads[(int)ch]++;
	}
	while ((ch = getchar()) != '\n') {
		beads[(int)ch]--;
	}
	for (i = 0; i < 128; i++) {
		if (beads[i] > 0) {
			more += beads[i];
		} else if (beads[i] < 0) {
			less -= beads[i];
		}
	}

	if (less) {
		printf("No %d\n", less);
	} else {
		printf("Yes %d\n", more);
	}		
	return 0;
}
