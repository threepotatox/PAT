/*
 * 设计思路：
 * 直接申请 <limits.h> 中 INT_MAX 大小的数组，居然 AC 了
 */

#include <stdio.h>
#include <limits.h>

//int MAX = INT_MAX;//(unsigned)(-1) >> 1;
//MIN = ~MAX;
int map[INT_MAX];

int main(void)
{
	int n, i, t;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t > 0)
			map[t] = 1;
	}
	for (i = 1; i < INT_MAX; i++)
		if (map[i] == 0)
			break;
	printf("%d", i);

	return 0;
}
