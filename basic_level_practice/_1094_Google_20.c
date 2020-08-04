/*
 * 设计思路：
 * 截取字符串，转换成数字，判断是否为素数
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isprime(int n)
{
	if (n < 2)
		return 0;
	int i;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main()
{
	char n[1000], str[10] = {0};
	int l, k, i;

	scanf("%d %d %s", &l, &k, n);
	for (i = 0; i <= l - k; i++) {
		strncpy(str, n + i, k);
		if (isprime(atoi(str))) {
		       printf("%s", str);
		       return 0;
		}
	}

	printf("404");
	return 0;
}
