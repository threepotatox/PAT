/*
 * 设计思路：
 * 1. 两个数均转化为 10 进制数进行比较
 * 2. 寻找另一个数的基数时：
 *      * 确定基数的最小值和最大值
 *      * 二分法查找基数
 * 3. 当另一个数只有一位时，在任何大于它本身的基数下，其值均等于它自身：
 *      * 如果等于已知数，最小进制为自身加 1
 *      * 否则无解
 */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

#define CBASE10(C) ((C) >= '0' && (C) <= '9' ? (C) - '0' : (C) - 'a' + 10)

long long convert10(char *s, long long radix);
long long minradix(char *s);
long long binsearch(char *s, long long n, long long rmin, long long rmax);

int main(void)
{
	long long tag, radix;
	char n1[11], n2[11], *s1, *s2;
	long long r, m1, rmin, rmax;

	scanf("%s %s %d %d", n1, n2, &tag, &radix);
	if (tag == 1) {
		s1 = n1;
		s2 = n2;
	} else {
		s1 = n2;
		s2 = n1;
	}

	m1 = convert10(s1, radix);
	rmin = minradix(s2);
	rmax = LLONG_MAX;
	if (strlen(s2) == 1) {
		if (m1 == rmin - 1)
			printf("%lld", rmin);
		else
			printf("Impossible");
	} else {
		r = binsearch(s2, m1, rmin, rmax);
		if (r != -1)
			printf("%lld", r);
		else
			printf("Impossible");
	}

	return 0;
}

long long convert10(char *s, long long radix)
{
	long long n, sum;
	for (sum = 0; *s; s++) {
		n = CBASE10(*s);
		if((LLONG_MAX - n) / radix < sum)
			return -1;
		sum = sum * radix + n;
	}
	return sum;
}

long long minradix(char *s)
{
	char r;
	long long n;
	for (r = '0'; *s; s++)
		if (*s > r)
			r = *s;
	return CBASE10(r) + 1;
}

long long binsearch(char *s, long long n, long long rmin, long long rmax)
{
	long long r, m;
	while (rmax >= rmin) {
		r = rmin + (rmax - rmin) / 2;
		if ((m = convert10(s, r)) > n || m == -1)
			rmax = r - 1;
		else if (m < n)
			rmin = r + 1;
		else
			return r;
	}
	return -1;
}
