/*
 * 设计思路：
 * * 利用结构体数组储存节点，数组索引当作地址
 * * 从头结点遍历链表，并把节点地址按序存储在另一个地址数组中，同时记录有效节点总数
 * * 根据节点 Key 值，对地址数组排序
 * * 排序后按照要求输出
 *
 * 注：
 * * 可能存在无效节点
 * * 除 -1 外的有效地址，均要补 0 输出
 * * 此链表为空时，输出 "0 -1"，表示节点数为 0，头结点为 -1，无节点需要输出
 */

#include <stdio.h>

struct node {
	int val, next;
};

struct node nodes[100000] = {0};

int cmp(const void *a, const void *b)
{
	return nodes[*(int *)a].val - nodes[*(int *)b].val;
}

int main(void)
{
	int addrs[100000] = {0}, count = 0;
	int n, head;
	int a, b, c;
	int i;

	scanf("%d %d", &n, &head);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		nodes[a].val = b;
		nodes[a].next = c;
	}
	for (i = head; i != -1; i = nodes[i].next) {
		addrs[count] = i;
		count++;
	}

	if (count) {
		qsort(addrs, count, sizeof(addrs[0]), cmp);
		printf("%d %05d\n%05d %d ", count, addrs[0], addrs[0], nodes[addrs[0]].val);
		for (i = 1; i < count; i++) {
			printf("%05d\n%05d %d ", addrs[i], addrs[i], nodes[addrs[i]].val);
		}
		printf("-1\n");
	} else {
		printf("0 -1\n");
	}

	return 0;
}
