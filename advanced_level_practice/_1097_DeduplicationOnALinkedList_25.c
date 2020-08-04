/*
 * 设计思路：
 * * 第一遍遍历，利用 num[] 数组输出绝对值不重复的节点，并把输出的节点标记
 * * 第二遍遍历，输出未被标记的节点
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int d, next;
	int flag;
};

int main(void)
{
	int root, n, root2 = -1;
	struct node list[100000] = {0};
	int num[10010] = {0};
	int i, t, f;

	scanf("%d%d", &root, &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		scanf("%d%d", &list[t].d, &list[t].next);
	}
	f = 0;
	i = root;
	if (i != -1) {
		f = 1;
		printf("%05d %d ", i, list[i].d);
		list[i].flag = 1;
		num[abs(list[i].d)] = 1;
		i = list[i].next;
	}
	while (i != -1) {
		if (num[abs(list[i].d)] == 0) {
			printf("%05d\n%05d %d ", i, i, list[i].d);
			list[i].flag = 1;
			num[abs(list[i].d)] = 1;
		} else {
			if (root2 < 0)
				root2 = i;
		}
		i = list[i].next;
	}
	if (f == 1)
		printf("-1\n");
	f = 0;
	i = root2;
	if (i != -1) {
		f = 1;
		printf("%05d %d ", i, list[i].d);
		i = list[i].next;
	}
	while (i != -1) {
		if (list[i].flag == 0)
			printf("%05d\n%05d %d ", i, i, list[i].d);
		i = list[i].next;
	}
	if (f == 1)
		printf("-1\n");
	return 0;
}
