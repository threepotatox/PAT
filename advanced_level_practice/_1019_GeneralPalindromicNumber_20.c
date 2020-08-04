/*
 * 设计思路：
 * * 进制转换，回文数判断
 */

#include <stdio.h>

int main(void)
{
	int n, b, len;
	int base[30] = {0}, ispalindromic = 1;
	int i;

	scanf("%d %d", &n, &b);

	for (len = 0; n; n /= b, len++)
		base[len] = n % b;

	for (i = 0; i < len / 2 && ispalindromic; i++)
		if (base[i] != base[len - i - 1])
			ispalindromic = 0;

	printf("%s\n", ispalindromic ? "Yes" : "No");
	if (len) {
		i = len - 1;
		printf("%d", base[i]);
		for (i--; i >= 0; i--)
			printf(" %d", base[i]);
	} else {
		printf("0");
	}

	return 0;
}
