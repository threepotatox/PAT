/*
设计思路：
1.用 scanf("%8s", str) 处理输入，因为”合法“输入最大字节数为 8 字节，所以一次读取 8 个字节或遇到空字符停止读取
2.double strtod(const char *str, char **endptr) 函数转换字符串为浮点数
3.char *strchr(const char *str, int c) 函数找小数点的位置
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, count = 0;
	double f, sum = 0;
	char s[9], *send, *sdot, c;
	
	scanf("%d", &n);
	while (n--) {
		scanf("%8s", s);
		c = ungetc(getchar(), stdin);
		f = strtod(s, &send);
		sdot = strchr(s, '.');

		if(!isspace(c)
		|| *send
		|| (f> 1000 || f < -1000)
		|| (sdot && sdot - s < strlen(s) - 3)) {
			printf("ERROR: %s", s);
			while (!isspace(c = getchar()))
				putchar(c);
			printf(" is not a legal number\n");
		} else {
			count++;
			sum += f;
		}
	}

	if (count == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (count == 1)
		printf("The average of 1 number is %.2lf", sum);
	else
		printf("The average of %d numbers is %.2lf", count, sum/count);
	
	return 0;
}
