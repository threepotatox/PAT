/*
 * 设计思路：
 * 1.用数组下标表示绳子长度
 * 2.用数组记录每种长度绳子的个数
 * 3.由最小值开始折叠绳子，完毕即为最大值
 *
 * 感谢 OliverLew (LuXu) 大佬：
 * https://oliverlew.github.io/PAT/Basic/1070.html
 */

#include <stdio.h>

int main()
{
	int n, l[10001] = {0};
	int i, tmp;
	double length = 0.0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		l[tmp]++;
	}
	for (i = 0; i < 10001; i++) {
		if (l[i]) {
			length = (double)i;
			break;
		}
	}

	for (; i < 10001; i++)
		while (l[i]--)
			length = (length + i) / 2;
	printf("%d\n", (int)length);

	return 0;
}
