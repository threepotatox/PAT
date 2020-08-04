/*
 * 设计思路：
 * DFS
 * * DFS 求连通分量，若大于 1，直接输出连通分量数
 * * 若能构成树，再一次 DFS，寻找最大深度的根节点：
 *     * 从第一次 DFS 得到的最大深度节点集合中，任选一个开始，再次得到一个最大深度节点的集合，两个节点集合的并集即为所求
 */

#include <stdio.h>

struct node {
	int visit, level, depth;
	struct adj *adj;
};

struct adj {
	struct node *node;
	struct adj *next;
};

struct temp {
	int q[10000];
	int c;
};

struct temp temp;
int maxheight;

void dfs(struct node *n, int height)
{
	if (height > maxheight) {
		temp.c = 0;
		temp.q[temp.c] = n->level;
		temp.c++;
		maxheight = height;
	} else if (height == maxheight) {
		temp.q[temp.c] = n->level;
		temp.c++;
	}
	n->visit = 1;
	struct adj *a;
	for (a = n->adj; a; a = a->next) {
		if (a->node->visit == 0)
			dfs(a->node, height + 1);
	}
}
int main(void)
{
	int n, a, b;
	struct node nodes[10000] = {0}, *pnode;
	struct adj edges[20000] = {0}, *padj;
	int i, count;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		nodes[i].level = i;
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		pnode = &nodes[a - 1];
		padj = &edges[i * 2];
		padj->node = &nodes[b - 1];
		padj->next = pnode->adj;
		pnode->adj = padj;

		pnode = &nodes[b - 1];
		padj = &edges[i * 2 + 1];
		padj->node = &nodes[a - 1];
		padj->next = pnode->adj;
		pnode->adj = padj;
	}

	count = 0; maxheight = 0;
	for (i = 0; i < n; i++) {
		if (nodes[i].visit == 0) {
			dfs(nodes + i, 1);
			count++;
		}
	}

	if (count > 1) {
		printf("Error: %d components\n", count);
	} else {
		int num[10000] = {0};
		for (i = 0; i < n; i++)
			nodes[i].visit = 0;
		for (i = 0; i < temp.c; i++)
			num[temp.q[i]]++;
		maxheight = 0; temp.c = 0;
		dfs(nodes + temp.q[0], 1);
		for (i = 0; i < temp.c; i++)
			num[temp.q[i]]++;
		for (i = 0; i < 10000; i++)
			if (num[i])
				printf("%d\n", i + 1);
	}
	return 0;
}
