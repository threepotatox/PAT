/*
 * 设计思路：
 * 每次利用前一个字符串生成下一个字符串，难点似乎在于如何确定字符数组的大小（实际上，数组大小多提交几次就能知道了(╥﹏╥)）？或者是我未体会到此题的精髓？求大佬解答_(┐「ε:)_
 */

#include <stdio.h>

int exterior(char *s1, char *s2);

int main()
{
	char str1[100000] = {0}, str2[100000] = {0};
	int n, i;

	scanf("%s %d", str1, &n);

	for (i = 1; i < n; i++)
		i % 2 ? exterior(str1, str2) : exterior(str2, str1);
	
	puts(i % 2 ? str1 : str2);

	return 0;
}

int exterior(char *s1, char *s2)
{
	int count = 0;
	while (*s1) {
		count++;
		if (*s1 != *(s1 + 1)) {
			*s2++ = *s1;
			*s2++ = count + '0';
			count = 0;
		}
		s1++;
	}
	return 0;
}
