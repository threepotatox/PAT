/*
 * 设计思路：
 * 元素排序，前一半为集合 1，后一半为集合 2，计算输出
 */

#include <stdio.h>

int cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int main(void)
{
	int n, a[100010];
	int i;
	int s1 = 0, s2 = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);
	qsort(a, n, sizeof(a[0]), cmp);
	for (i = 0; i < n / 2; i++)
		s1 += a[i];
	for (i; i < n; i++)
		s2 += a[i];
	printf("%d %d", n % 2, s2 - s1);
	return 0;
}
