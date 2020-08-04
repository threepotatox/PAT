/*
 * 设计思路：
 * 如果有 Hash 会很简单，直接利用 Hash 表统计对应单词的个数，输出最多的即可
 *
 * 本题利用指针数组对单词按字典序排序，获得单词个数
 * * 逐个字母读入字符串，将非单词部分转换为 '\0'，以表示每个单词的结尾，例如：
 *   * Can1: "Can a can can a can?  It can!"
 *   * can1'\0'can'\0'a'\0'can'\0'can'\0'a'\0'can'\0'it'\0'can'\0'
 *   * 指针数组指向每个单词的首地址，利用指针数组对单词按字典序从小到大排序，从大到小统计，然后输出
 *
 * 注意字符串最后要加 '\0'：例如下面的字符串，最后以正常单词结尾，最后要在读取完毕后额外加上 '\0'
 *   * can1:!can
 *   * can'1\0'can'\0'
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char a[1048578], *s[1048578];
int cnt;

int cmp(const void *a, const void *b)
{
	return strcmp(*((char **)a), *((char **)b));
}

int main(void)
{
	char ch, *p = &a[0];
	int i = 1;
	while ((ch = getchar()) && ch != '\n') {
		if (ch >= 'A' && ch <= 'Z') {
			a[i++] = tolower(ch);
		} else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
			a[i++] = ch;
		} else {
			if (a[i - 1] != '\0') {
				s[cnt++] = p + 1;
				a[i] = '\0';
				p = &a[i];
				i++;
			}
		}
	}
	if (a[i - 1] != '\0') {
		s[cnt++] = p + 1;
		a[i] = '\0';
		p = NULL;
	}

	qsort(s, cnt, sizeof(s[0]), cmp);

	char *result = NULL;
	int j, maxsum = -1, sum;
	for (j = cnt - 1, sum = 0; j >= 1; j--) {
		if (strcmp(s[j], s[j - 1]) == 0) {
			sum++;
		} else {
			if (sum + 1 >= maxsum) {
			maxsum = sum + 1;
			result = s[j];
			}
			sum = 0;
		}
	}
	if (sum + 1 >= maxsum)  {
		maxsum = sum + 1;
		result = s[j];
		sum = 0;
	}

	printf("%s %d", result, maxsum);	
	return 0;
}
