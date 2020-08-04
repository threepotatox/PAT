/*
 * 设计思路：
 * 1.分解成一个压缩函数，一个解压缩函数，处理即可
 * 2.注意解压缩时数字的处理
 */

#include <stdio.h>

int compression();
int decompression();

int main()
{
	switch (getchar()) {
	case 'C':
		while (getchar() != '\n')
			continue;
		compression();
		break;
	case 'D':
		while (getchar() != '\n')
			continue;
		decompression();
		break;
	default:
		break;
	}

	return 0;
}

int compression()
{
	char ch, tmp;
	int count = 1;
	
	ch = getchar();
	while ((tmp = getchar())) {
		if (tmp == ch) {
			count++;
		} else {
			if (count > 1)
				printf("%d", count);
			putchar(ch);
			ch = tmp;
			count = 1;
		}

		if (ch == '\n')
			break;
	}

	return 0;
}

int decompression()
{
	char ch;
	int count = 0, i;

	while ((ch = getchar()) != '\n') {
		if (ch >= '0' && ch <= '9') {
			count = count * 10 + (ch - '0');
		} else {
			if (count == 0)
				count = 1;
			for (i = 0; i < count; i++)
				putchar(ch);
			count = 0;
		}
	}

	return 0;
}
