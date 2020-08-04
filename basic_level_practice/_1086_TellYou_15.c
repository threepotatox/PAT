/*
 * 设计思路：
 * 算完利用取余输出就好
 */

#include <stdio.h>

int main()
{
	int a, b, tmp;

	scanf("%d %d", &a, &b);
	tmp = a * b;
	while (!(tmp % 10))
		tmp /= 10;
	do {
		printf("%d", tmp % 10);
	} while (tmp /= 10);

	return 0;
}
