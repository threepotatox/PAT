/*
 * 设计思路：
 * 1.利用数组记录差值
 * 2.输出有重复的差值，即出现次数大于 2 的（囧，出现次数为 1，不叫重复，咦？我为什么要写这句话）
 */

#include <stdio.h>

int main()
{
	int n, num, diff[10000] = {0};
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		diff[num > i + 1 ? (num - i - 1) : (i + 1 - num)]++;
	}

	for (i = n - 1; i >= 0; i--)
		if (diff[i] >= 2)
			printf("%d %d\n", i, diff[i]);

	return 0;
}
