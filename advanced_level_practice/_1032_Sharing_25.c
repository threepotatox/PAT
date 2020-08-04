/*
 * 设计思路：
 * 首先遍历两个链表得到各自的长度；第二次遍历，先让长的链表走若干步，使剩下的长度和短的链表长度相同；然后，同时在两个链表上遍历，找到第一个相同的节点即第一个公共节点。
 *
 * 但本程序使用了额外的空间，让时间复杂度更极端一点（只是尽可能尝试不同的思路）。先遍历第一条链表，将访问的节点标记，再遍历第二条链表时，遇到的第一个访问过的节点，即为第一个公共节点。
 */

#include <stdio.h>

struct node {
	int next;
	int flag;
};

int main(void)
{
	struct node link[100000] = {0};
	int s1, s2, n;
	int i, a, b;
	char ch;

	scanf("%d %d %d", &s1, &s2, &n);
	for (i = 0; i < n; i++) {
		scanf("%d %c %d", &a, &ch, &b);
		link[a].next = b;
	}

	for (i = s1; i != -1; i = link[i].next) {
		link[i].flag = 1;
	}
	for (i = s2; i != -1 && link[i].flag == 0; i = link[i].next) {
		;
	}

	if (i != -1) {
		printf("%05d", i);
	} else {
		printf("%d", i);
	}

	return 0;
}
