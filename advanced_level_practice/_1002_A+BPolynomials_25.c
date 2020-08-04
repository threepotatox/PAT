/*
 * 设计思路：
 * * 利用数组下标表示指数，数组本身存取对应系数
 */

#include <stdio.h>

int main()
{
	double exs[1001] = {0.0};
	double co;
	int k, i, j, ex;

	for (i = 0; i < 2; i++) {
		scanf("%d", &k);
		for (j = 0; j < k; j++) {
			scanf("%d %lf", &ex, &co);
			exs[ex] += co;
		}
	}

	for (i = 0, j = 0; i < 1001; i++)
		if (exs[i] != 0)
			j++;
	printf("%d", j);
	for (i = 1000; i >= 0; i--)
		if (exs[i] != 0)
			printf(" %d %.1f", i, exs[i]);
	return 0;
}
