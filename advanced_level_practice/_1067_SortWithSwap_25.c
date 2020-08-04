/*
 * 题目大意：
 * 输入有 N 个数的序列，数字大小为 0 ~ N - 1 且乱序，每次用 0 和其他数两两交换位置，让序列有序，求需要多少次交换
 *
 * 设计思路：
 * 1. 若 0 在 i 位置，必定和这个 i 位置对应的数 i 交换，最终有序，
 * 2. 如果 0 在 0 位置上，那么就先和第一个不在 i 位置上的数交换，重复步骤 1，最终有序
 *
 * 想要交换两个数，必须知道这两个数在什么位置，所以开一个数组 pos[]，下标表示数字 i，值表示数字 i 在第几位，例如题目中 {4, 0, 2, 1, 3}
 * * 则 pos[0] = 1 表示 0 在 1 位上，那么 0 需要和 1 交换
 * * 则 pos[pos[0] = 1] = 3 表示 1 在 3 位上，那说明 0 和 1 交换后，0 必到 3 位
 * * 所以 swap(pos[0], pos[pos[0] = 1]) 表示 0 和 1 交换位置，最终 pos[1] = 1，pos[0] = 3，不断迭代，最终有序
 */

#include <stdio.h>

int swap(int *a, int x, int y)
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int main(void)
{
	int n;
	int num, index;
	int pos[100010], temp, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		pos[temp] = i;
	}
	for (i = 0; i < n; i++) {
		if (pos[i] != i) {
			while (pos[0] != 0) {
				swap(pos, 0, pos[0]);
				num++;
			}
			if (pos[i] != i) {
				swap(pos, 0, i);
				num++;
			}
		}
	}
	printf("%d", num);

	return 0;
}
