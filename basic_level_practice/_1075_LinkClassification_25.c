/*
 * 设计思路：
 * 1.题目中链表的地址从小到大排列，故可以利用数组下标当链表地址
 * 2.两个数组分别记录链表数据，链表 next 地址
 * 3.遍历链表输出
 */

#include <stdio.h>

int main()
{
	int data[100000] = {0}, next[100000] = {0};
	int n, k, first, addr, last = -1;
	int i;

	scanf("%d %d %d", &first, &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &addr);
		scanf("%d %d", data + addr, next + addr);
	}

	for (i = 0; i < 3; i++) {
		for (addr = first; addr != -1; addr = next[addr]) {
			if ((i == 0 && data[addr] < 0)
			||  (i == 1 && 0 <= data[addr] && data[addr] <= k)
			||  (i == 2 && data[addr] > k)) {
				if (last != -1)
					printf(" %05d\n", addr);
				printf("%05d %d", addr, data[addr]);
				last = addr;
			}
		}
	}
	printf(" -1\n");

	return 0;
}
