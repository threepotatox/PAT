/*
 * 设计思路：
 * 按每一位上不同的进制逐位计算
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char s[21] = {0}, a[21] = {0}, b[21] = {0}, sum[21] = {0};
	int ls, la, lb, ns, na, nb, lsum = 21;
	int i;
	
	scanf("%s %s %s", s, a, b);
	ls = strlen(s);
	la = strlen(a);
	lb = strlen(b);

	for (i = 0; i < ls; i++) {
		na = la <= i ? 0 : a[la - i - 1] - '0';
		nb = lb <= i ? 0 : b[lb - i - 1] - '0';
		ns = s[ls - i - 1] == '0' ? 10 : s[ls - i - 1] - '0';

		sum[lsum - i - 1] += na + nb;
		sum[lsum - i - 2] += sum[lsum - i - 1] / ns;
		sum[lsum - i - 1] = sum[lsum - i - 1] % ns;
	}

	for (i = 0; i < 21; i++)
		sum[i] += '0';

	for (i = 0; i < 21; i++)
		if (sum[i] != 0 && sum[i] != '0') {
			puts(sum + i);
			return 0;
		}

	printf("0\n");
	return 0;
}
