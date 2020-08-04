/*
 *设计思路：
 ** 使用格式化符号 `'`，但标准库不一定支持（万事开头难，快速 AC，进军 Advanced Level）
 ** 参考链接：[How to format a number from 1123456789 to 1,123,456,789 in C?](https://stackoverflow.com/questions/1449805/how-to-format-a-number-from-1123456789-to-1-123-456-789-in-c)
 */

#include <stdio.h>
#include <locale.h>

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);
	setlocale(LC_ALL,"");
	printf("%'d", a + b);

	return 0;
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	int a, b;
	char num[10] = {0};
	char *p = num;

	scanf("%d %d", &a, &b);
	sprintf(num, "%d", a + b);

	if (*p == '-') {
		printf("-");
		p++;
	}
	int c = strlen(p) % 3;
	if (c == 0)
		c = 3;
	for (; *p != 0; p++) {
		if (c == 0) {
			printf(",");
			c = 3;
		}
		putchar(*p);
		c--;
	}

	return 0;
}
*/
