/*
 * 设计思路：
 * 贪心算法：
 * * 分别对两个序列按相同顺序排序，这里是从小到大的顺序
 * * 前面都是负数的元素相乘，后面都是正数的元素相乘，累计求和，即为最大值
 */

#include <stdio.h>

int cmp(const void *a, const void *b)
{
	int *n1 = (int *)a, *n2 = (int *)b;
	return *n1 - *n2;
}

int main(void)
{
	int nc, np;
	int coupon[100000] = {0}, product[100000] = {0};
	int i, p, q, sum;

	scanf("%d", &nc);
	for (i = 0; i < nc; i++) {
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &np);
	for (i = 0; i < np; i++) {
		scanf("%d", &product[i]);
	}

	qsort(coupon, nc, sizeof(coupon[0]), cmp);
	qsort(product, np, sizeof(product[0]), cmp);

	sum = 0;
	p = 0;
	q = 0;
	while (p < nc && q < np && coupon[p] < 0 && product[q] < 0) {
		sum += coupon[p] * product[q];
		p++;
		q++;
	}
	p = nc - 1;
	q = np - 1;
	while (p >= 0 && q >= 0 && coupon[p] > 0 && product[q] > 0) {
	 	sum += coupon[p] * product[q];
		p--;
		q--;
	}

	printf("%d", sum);
	return 0;
}
