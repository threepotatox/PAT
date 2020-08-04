/*
 * 设计思路：
 * 利用二分查找，没有不相容物品即可装箱
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n, m, k;
	int list[10000][2] = {{0}}, tmp[1000];
	int i, j, f;

	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d %d", &list[i][0], &list[i][1]);
	for (i = 0; i < m; i++) {
		f = 1;
		scanf("%d", &k);
		for (j = 0; j < k; j++)
			scanf("%d", tmp + j);

		qsort(tmp, k, sizeof(int), cmp);

		for (j = 0; j < n; j++) {
			if (bsearch(&list[j][0], tmp, k, sizeof(int), cmp)
			&&  bsearch(&list[j][1], tmp, k, sizeof(int), cmp)) {
				puts("No");
				f = 0;
				break;
			}
		}
		if (f)
			puts("Yes");
	}

	return 0;
}
