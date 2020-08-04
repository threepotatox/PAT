/*
 * 设计思路：
 * 主要是 ling 的处理，和位的处理
 * * 一个字符数组记录数字，一个字符数组记录位
 * * 字符数组第 0 位为空是因为使其下标从 1 开始用
 * * 字符数组最后一位为空是因为个位不输出
 * * 把输入的数字，先处理正负号，然后用前导 0 填充满 10 位数，
 * * 每四位为一组，以输出特殊的亿位，万位，个位
 * * 输出位信息前一定会先输出数字信息，所以在位的字符数组中提前加入空格，输出时就不用再考虑空格了，而个位的位为空
 * * 输出过程中注意 ling 的判断，多个连续的 0，要符合汉字读法，省略成一个 ling
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *num[]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	char *wei[]={"", " Yi", " Qian", " Bai", " Shi", " Wan", " Qian", " Bai", " Shi", ""};
	char s[11] = {0};
	int i, j, len, flag;

	gets(s);
	if (atoi(s) == 0) {
		printf("%s", num[0]);
	} else {
		if (s[0] == '-') {
			printf("Fu ");
			s[0] = '0';
		}
		len = strlen(s);
		for (i = len - 1, j = 9; i >= 0; i--, j--)
			s[j] = s[i];
		for (;j >= 0; j--)
			s[j] = '0';

		for (i = 0; s[i] == '0'; i++)
			;
		printf("%s%s", num[s[i] - '0'], wei[i]);
		flag = 0;
		for (i++; i <= 9; i++) {
			if (i % 4 == 1) {
				if (s[i] == '0') {
					printf("%s", wei[i]);
				} else {
					if (flag == 1) {
						printf(" ling %s%s", num[s[i] - '0'], wei[i]);
						flag = 0;
					} else {
						printf(" %s%s", num[s[i] - '0'], wei[i]);
					}
				}
			} else {
				if (s[i] == '0') {
					flag = 1;
				} else {
					if (flag == 1) {
						printf(" ling %s%s", num[s[i] - '0'], wei[i]);
						flag = 0;
					} else {
						printf(" %s%s", num[s[i] - '0'], wei[i]);
					}
				}
			}
		}
		
	}
	return 0;
}
