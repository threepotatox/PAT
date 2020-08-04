/*
 * 设计思路：
 * 两个数组，一个按顺序储存数字，另一个利用索引值储存对应数字的出现次数，再按顺序遍历一遍查找第一个仅出现一次的数字
 */

#include <stdio.h>

int main(void)
{
	int num[100001] = {0}, c[100001] = {0};
	int n;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		c[num[i]]++;
	}
	for (i = 0; i < n; i++) {
		if (c[num[i]] == 1) {
			printf("%d", num[i]);
			return 0;
		}
	}
	if (i >= n) {
		printf("None");
	}

	return 0;
}
