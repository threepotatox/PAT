/*
 * 设计思路：
 * 数组索引，映射 S2 中出现的字符，根据映射数组重新输出 S1
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int flag[128] = {0};
	char str[10001], ch;
	int i;
	gets(str);
	while ((ch = getchar()) && ch != '\n') {
		flag[ch - '\0'] = 1;
	}
	for (i = 0; str[i] != '\0'; i++) {
		if (flag[str[i] - '\0'] == 0) {
			putchar(str[i]);
		}
	}
	return 0;
}
