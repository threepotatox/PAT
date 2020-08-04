/*
 * 设计思路：
 * 似乎又是如何正确读取输入的题目
 */

#include <stdio.h>

int main()
{
	char string[] = {"1234"}, ch[4];

	while (scanf("%s", ch) != EOF)
		if (ch[2] == 'T')
			putchar(string[ch[0] - 'A']);
	return 0;
}
