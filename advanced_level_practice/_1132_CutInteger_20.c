/*
 * 设计思路：
 * 以字符串的形式读入数据 N
 * * 分成前后两部分判断
 * * 注意判断 A、B 不能为 0
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[11] = {0};
	int n, len;
	long long z, a, b;

	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		len = strlen(s);
		z = atol(s);
		b = atol(s + len / 2);
		s[len / 2] = '\0';
		a = atol(s);
		if (a != 0 && b != 0 && z % (a * b) == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
