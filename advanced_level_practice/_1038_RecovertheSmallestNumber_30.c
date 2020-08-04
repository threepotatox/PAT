/*
 * 设计思路：
 * 贪心算法：
 * * 对数字串排序，按照相邻两个字符串组成的字符串大小排序：
 *     * 形似 return (a + b) < (b + a);
 * * 这样排序后保证了每相邻两个子串组成的数字最小，保证了最终组成的数字最小；
 * * 注意前导 0 的处理，若最终组成的数是 0，也要输出一个 0；
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	char s1[17] = {0}, s2[17] = {0};
	sprintf(s1, "%s%s", (char *)a, (char *)b);
	sprintf(s2, "%s%s", (char *)b, (char *)a);
	return strcmp(s1, s2);
}

int main(void)
{
	int n;
	char num[10000][9] = {0};
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %s", num[i]);
	}

	qsort(num, n, sizeof(num[0]), cmp);

	int flag = 0;
	for (i = 0; i < n && flag == 0; i++) {
		char *p = &num[i][0];
		while (*p != '\0' && flag == 0) {
			if (*p == '0') {
				p++;
			} else {
				flag = 1;
				printf("%s", p);
			}
		}
	}
	while (i < n) {
		printf("%s", num[i]);
		i++;
	}
	if (flag == 0) {
		printf("0");
	}
	return 0;
}
