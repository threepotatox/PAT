/*
 * 设计思路：
 * 利用 ASCII 数组记录
 */

#include <stdio.h>

int main()
{
	char ch;
	int count = 0, ascii[128] = {0};

	while (count < 2) {
		ch = getchar();
		if (ch == '\n') {
			count++;
		} else if (!ascii[(int)ch]) {
			ascii[(int)ch]++;
			putchar(ch);
		}
	}

	return 0;
}
