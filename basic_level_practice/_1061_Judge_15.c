/*
 * 设计思路：
 * 两个数组，一个记录分值，一个记录正确答案
 */

#include <stdio.h>

int main()
{
	int n, m;
	int judge[100], answer[100];
	int score, choice;
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d", judge + i);
	for (i = 0; i < m; i++)
		scanf("%d", answer + i);

	for (i = 0; i < n; i++){
		score = 0;
		for (j = 0; j < m; j++){
			scanf("%d", &choice);
			if (choice == answer[j])
				score += judge[j];
		}
		printf("%d\n", score);
	}

	return 0;
}
