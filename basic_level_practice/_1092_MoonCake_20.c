/*
 * 设计思路:
 * 利用数组记录销量，找最大值输出
 */

#include <stdio.h>

int main()
{
	int n, m, tmp;
	int max = 0, sales[1000] = {0};
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &tmp);
			sales[j] += tmp;
		}
	}

	for (i = 0; i < n; i++)
		if (max < sales[i])
			max = sales[i];
	printf("%d", max);
	for (i = 0, j = 0; i < n; i++)
		if (sales[i] == max)
			printf("%c%d", j++ ? ' ' : '\n', i + 1);

	return 0;
}
