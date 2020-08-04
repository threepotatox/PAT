/*
 * 设计思路：
 * * 邻接链表存储所给的树
 * * DFS 遍历树，并记录各层节点的个数
 */

#include <stdio.h>

int tree[110][110], cnt[110];
int levelnum[110];

void dfs(int v, int level)
{
	int i;
	levelnum[level]++;
	for (i = 0; i < cnt[v]; i++)
		dfs(tree[v][i], level + 1);
}

int main(void)
{
	int n, m;
	int id, k, a;
	int i;

	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &id, &k);
		for (i = 0; i < k; i++) {
			scanf("%d", &a);
			tree[id][cnt[id]++] = a;
		}
	}
	dfs(1, 1);
	int max = 1;
	for (i = 2; i <= n; i++)
		if (levelnum[max] < levelnum[i])
			max = i;
	printf("%d %d", levelnum[max], max);

	return 0;
}
