/*
 * 设计思路：
 * * 父节点一直比子节点大为大顶堆，父节点一直比子节点小为小顶堆，否则不是堆
 * * 输出后序遍历
 */

#include <stdio.h>

void postorder(int *a, int i, int n)
{
	if (i > n)
		return ;
	postorder(a, i * 2, n);
	postorder(a, i * 2 + 1, n);
	printf("%d%s", a[i], i == 1 ? "\n" : " ");
}

int main(void)
{
	int a[1010], m, n;
	int i, max, min;

	scanf("%d%d", &m, &n);
	while (m--) {
		max = 1;
		min = 1;
		scanf("%d", &a[1]);
		for (i = 2; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] > a[i / 2])
				max = 0;
			if (a[i] < a[i / 2])
				min = 0;			
		}
		if (max == 1)
			printf("Max Heap\n");
		else if (min == 1)
			printf("Min Heap\n");
		else
			printf("Not Heap\n");
		postorder(a, 1, n);
	}
	return 0;
}
