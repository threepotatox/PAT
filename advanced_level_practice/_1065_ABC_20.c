/*
 * 题目大意：
 * 输入三个数，A、B、C，问是否 A + B > C
 *
 * 设计思路：
 * 乙级有一题类似，可以用 double 类型混过去，但此题数值过大，double 精度不够，用 long long 存值，并先判断正值溢出和负值溢出即可
 */

#include <stdio.h>

int main()
{
	int t, i;
	long long a, b, c, sum;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0)
			printf("Case #%d: true\n", i);
		else if (a < 0 && b < 0 && sum >= 0)
			printf("Case #%d: false\n", i);
		else if (sum > c)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	
	return 0;
}
