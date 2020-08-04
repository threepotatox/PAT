/*
 * * 版本二：利用字符串 2，寻找完好的键盘并标记，再利用字符串 1 和标记，输出损坏的键盘
 * * 版本一：利用字符串 1 和 字符串 2 双重遍历，寻找损坏的键盘，并直接输出
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int keyboard[128] = {0};
	char str[81], ch;
	int i;
	scanf("%s%c", str, &ch);
	while ((ch = getchar()) && ch != '\n') {
		keyboard[toupper(ch)] = 1;
	}
	for (i = 0; str[i] != '\0'; i++) {
		ch = toupper(str[i]);
		if (keyboard[ch - '\0'] == 0) {
			putchar(ch);
			keyboard[ch - '\0'] = -1;
		}
	}
	return 0;
}
