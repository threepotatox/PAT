/*
 * 设计思路：
 * 找平方和的最大值，然后开方输出
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int n, a, b, sum = 0;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		if (a * a + b * b > sum)
			sum = a * a + b * b;
	}
	printf("%.2lf\n", sqrt(sum));

	return 0;
}
