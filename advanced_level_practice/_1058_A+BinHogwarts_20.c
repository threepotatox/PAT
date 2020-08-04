/*
 * 题目大意：
 * 29 个 Knut 换一个 Sickle，17 个 Sickle 换一个 Galleon，加法运算输入的两组数据
 * 设计思路：
 * 加法的进位运算
 * 另一种思路，把所有的数换成 Knut，再按照规则输出
 */

#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f;

	scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);

	c = c + f;
	b = b + e + c / 29;
	a = a + d + b / 17;

	printf("%d.%d.%d", a, b % 17, c % 29);

	return 0;
}
