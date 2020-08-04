/*
 * 设计思路：
 * 直接暴力循环，枚举以 2 ~ 根号 N 开头的每个序列，最后序列长度为 0，说明是质数
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, m;
	int start = 0, cnt = 0;
	int i, j, k;

	scanf("%d", &n);
	m = (int)sqrt(n);
	for (i = 2; i <= m; i++) {
		k = 0;
		for (j = i; n % j == 0; j *= (i + k))
			k++;
		if (k > cnt) {
			cnt = k;
			start = i;
		}
	}
	if (cnt == 0) {
		printf("1\n%d", n);
	} else {
		printf("%d\n%d", cnt, start);
		for (i = 1; i < cnt; i++)
			printf("*%d", start + i);
	}
	return 0;
}
