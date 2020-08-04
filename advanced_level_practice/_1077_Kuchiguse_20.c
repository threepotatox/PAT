/*
 * 设计思路：
 * 1. 用指针数组记录每个字符串的尾地址，
 * 2. 用第一个字符串依次和其他字符串进行比较，尾字符相同，指针前移，
 *    1. 比较次数以最短字符串为准，防止越界
 *    2. 若公共后缀即为最短字符串，此时指针会在最短字符串的前 1 位置，所以指针要加 1 后输出，例如：
 *    3. ced 和 abcde 比较完成后，指针在 c 前面
 *    4. 输出最后指针所在的字符串即为公共后缀
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	char a[100][258], *b[100], *result;
	int i, j, len, min = 10000;

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		gets(a[i]);
		len = strlen(a[i]);
		b[i] = a[i] + len - 1;
		if (len < min)
			min = len;
	}
	int flag = 1;
	for (i = 0; i < min; i++) {
		for (j = 1; j < n; j++) {
			if (*b[0] == *b[j]) {
				b[j]--;
			} else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			b[0]--;
		} else {
			b[0]++;
			break;
		}
	}
	if (flag)
		puts(b[0] + 1);
	else if (*(b[0]) == '\0')
		puts("nai");
	else
		puts(b[0]);
	return 0;
}
