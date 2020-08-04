/*
 * 设计思路：
 * * 利用数组下标表示指数，数组本身存取对应系数
 */

#include <stdio.h>

int main(void)
{
	int n, exp, count = 0;
	float coef, a[1001] = {0}, b[1001] = {0}, c[2001] = {0};
	int i, j;

	scanf("%d", &n);
	while (n--) {
		scanf("%d %f", &exp, &coef);
		a[exp] = coef;
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d %f", &exp, &coef);
		b[exp] = coef;
	}

	for (i = 0; i < 1001; i++)
		for (j = 0; j < 1001; j++)
			c[i + j] += a[i] * b[j];

	for (i = 0; i < 2001; i++)
		if (c[i])
			count++;

	printf("%d", count);
	for (i = 2000; i >= 0; i--)
		if (c[i])
			printf(" %d %.1f", i, c[i]);

	return 0;
}
