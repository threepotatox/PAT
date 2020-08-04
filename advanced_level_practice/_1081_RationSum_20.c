/*
 * 设计思路：
 * * 辗转相除法求两个数的最大公约数
 * * long long 存数据，计算过程中要约分，否则会溢出
 */

#include <stdio.h>

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
	int n, i;
	long long sumzi = 0, summu = 1, zi, mu, k;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld/%lld", &zi, &mu);
		sumzi = sumzi * mu + zi * summu;
		summu = summu * mu;
		k = gcd(sumzi, summu);
		sumzi /= k;
		summu /= k;
	}
	k = sumzi / summu;
	sumzi = sumzi % summu;
	if (k != 0 && sumzi != 0)
		printf("%lld %lld/%lld", k, sumzi, summu);
	else if (k == 0 && sumzi != 0)
		printf("%lld/%lld", sumzi, summu);
	else
		printf("%lld", k);

	return 0;
}
