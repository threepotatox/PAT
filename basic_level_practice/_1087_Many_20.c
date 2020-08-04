/*
 * 设计思路：
 * 随之代入的数越大，题目中表达式算出的值越大，只要计算出不同的值，count++
 */

#include <stdio.h>

int main()
{
	int n;
	int i, m, m0 = -1, count = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		m = i / 2 + i /3 + i / 5;
		if (m > m0)
			count++;
		m0 = m;
	}

	printf("%d", count);

	return 0;
}
