/*
 * 设计思路：
 * * 输入过程中选择最大赔率，同时累乘最大值
 */

#include <stdio.h>

int main(void)
{
	char c, s[4] = {"WTL"};
	double odd, maxodd, maxvalue = 1.0;
	int i, j;

	for (i = 0; i < 3; i++) {
		maxodd = 0;
		for (j = 0; j < 3; j++) {
			scanf("%lf", &odd);
			if (odd > maxodd) {
				maxodd = odd;
				c = s[j];
			}
		}
		maxvalue *= maxodd;
		printf("%c ", c);
	}
	printf("%.2lf", (maxvalue * 0.65 - 1) * 2);

	return 0;
}
