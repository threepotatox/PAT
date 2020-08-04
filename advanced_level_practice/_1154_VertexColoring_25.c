/*
 * 设计思路：
 * * 把图的所有边存起来
 * * 每次查询，遍历每条边，检查颜色
 * * 颜色的个数排序后去重
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int get_cnt(int *a, int n)
{
	int i, j;
	qsort(a, n, sizeof(a[0]), cmp);
	for (j = 1; j < n && a[j] != a[j - 1]; j++)
		;
	for (i = j - 1,	j = j + 1; j < n; j++)
		if (a[i] != a[j])
			a[++i] = a[j];
	return i + 1;			
}

int main(void)
{
	int n, m, k, e[10010][2], c[10010];
	int i, j, f;

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d %d", &e[i][0], &e[i][1]);
	scanf("%d", &k);
	while (k--) {
		f = 1;
		for (i = 0; i < n; i++)
			scanf("%d", &c[i]);
		for (i = 0; i < m; i++) {
			if (c[e[i][0]] == c[e[i][1]]) {
				f = 0;
				break;
			}
		}
		if (f)
			printf("%d-coloring\n", get_cnt(c, n));
		else
			printf("No\n");
	}
	return 0;
}
