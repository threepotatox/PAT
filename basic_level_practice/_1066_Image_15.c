/*
 * 设计思路：
 * 依据题目要求输出即可
 */

#include <stdio.h>

int main()
{
	int m, n, a, b, k;
	int i, j, tmp;

	scanf("%d %d %d %d %d", &m, &n, &a, &b, &k);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &tmp);
			if (a <= tmp && tmp <= b)
				tmp = k;
			printf("%03d%c", tmp, j == n - 1 ? '\n' : ' ');
		}
	}

	return 0;
}
