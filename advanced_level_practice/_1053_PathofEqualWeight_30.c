/*
 * 设计思路：
 * 深度优先遍历
 * * 每个父节点接收储存完子节点后，按照子节点权重从大到小的顺序重新排序储存
 * * 深度优先遍历此树，将符合条件的路径输出
 */

#include <stdio.h>

struct node {
	int w;
	int c;
	int child[101];
};

struct node nodes[101] = {0};
int n, m, s;
int path[101] = {0};

int cmp(const void *a, const void *b)
{
	return nodes[*(int *)b].w - nodes[*(int *)a].w;
}

void dfs(int index, int num, int sum)
{
	if (sum > s) {
		return ;
	}
	if (sum == s) {
		if (nodes[index].c != 0) {
			return ;
		}
		int j = 0;
		for (; j < num; j++) {
			printf("%d%c", nodes[path[j]].w, j != num - 1 ? ' ' : '\n');
		}
		return ;
	}
	int i = 0;
	for (; i < nodes[index].c; i++) {
		int node = nodes[index].child[i];
		path[num] = node;
		dfs(node, num + 1, sum + nodes[node].w);
	}
}

int main(void)
{
	int i, j, f, c;

	scanf("%d %d %d", &n, &m, &s);
	for (i = 0; i < n; i++) {
		scanf("%d", &nodes[i].w);
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &f, &c);
		for (j = 0; j < c; j++) {
			scanf("%d", &nodes[f].child[j]);
			nodes[f].c++;
		}
		qsort(nodes[f].child, c, sizeof(nodes[f].child[0]), cmp);
	}

	dfs(0, 1, nodes[0].w);

	return 0;
}
