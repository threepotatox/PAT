/*
 * 设计思路：
 * * 判断是否在同行、同列
 * * 判断是否在同对角线：两个点的横坐标之差是否等于纵坐标之差
 */

#include <stdio.h>
#include <stdlib.h>

int judge(int *a, int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			if (a[i] == a[j] || abs(j - i) == abs(a[j] - a[i]))
				return 0;
	return 1;
}

int main(void)
{
	int k, n, a[1010];
	int i;

	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		printf("%s\n", judge(a, n) ? "YES" : "NO");
	}
	return 0;
}
