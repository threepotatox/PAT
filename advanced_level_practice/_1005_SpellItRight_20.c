/*
 * 设计思路：
 * * 利用数组索引
 */

#include <stdio.h>

int main(void)
{
	int sum = 0;
	char ch, *digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	while ((ch = getchar()) != '\n')
		sum += (ch - '0');

	if (sum >= 100)
		printf("%s ", digits[sum / 100]);
	if (sum >= 10)
		printf("%s ", digits[sum % 100 / 10]);
	printf("%s", digits[sum % 10]);

	return 0;
}
