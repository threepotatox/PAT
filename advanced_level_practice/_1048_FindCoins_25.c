/*
 * 设计思路：
 * * 利用数组和数组索引存每个数出现的次数，遍历寻找到第一对符合条件的，即可输出，
 * * 因为遍历过程中，索引从小到大，相当于数值从小到大遍历，可以保证 V<sub>1</sub> 是最小值
 */

#include <stdio.h>

int main(void)
{
	int n, m, temp;
	int map[501] = {0};
	int i;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		map[temp]++;
	}

	for (i = 0; i < 501; i++) {
		if (map[i]) {
			map[i]--;
			temp = m - i;
			if (0 <= temp && temp <= 500 && map[temp]) {
				printf("%d %d", i, temp);
				return 0;
			}
			map[i]++;
		}
	}
	printf("No Solution");

	return 0;
}
