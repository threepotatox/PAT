/*
 * 设计思路：
 * 输入 0 ~ 168 的十进制，转换十三进制不会超过两位数
 */

#include <stdio.h>

int main(void)
{
	char convert[]= "0123456789ABC";
	int n;
	int i;

	for (i = 0; i < 3; i++) {
		scanf("%d", &n);
		if (i == 0)
			printf("#");
		printf("%c%c", convert[n / 13], convert[n % 13]);
	}
	return 0;
}
