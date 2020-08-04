/*
 * 设计思路：
 * * 判断数本身，判断反转数，输出
 */

#include <stdio.h>

int isprime(int n)
{
	int i;
	if (n == 0 || n == 1)
		return 0;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int rev(int n, int d)
{
	int nrev = 0;
	while (n) {
		nrev *= d;
		nrev += n % d;
		n /= d;
	}
	return nrev;
}

int main(void)
{
	int n, d;

	while (scanf("%d %d", &n, &d) == 2)
		puts(isprime(n) && isprime(rev(n, d)) ? "Yes" : "No");

	return 0;
}
