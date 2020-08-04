/*
 * 设计思路：
 * 图的遍历
 *
 * * 实际上本题是求，图中删除一个节点后，剩余图的连通分量是多少；
 * * 添加的最少路线，就是连通分量数 - 1；
 */

#include <stdio.h>

void dfs(int n, int node, int visit[], int graph[][1001])
{
	int i;
	visit[node] = 1;
	for (i = 1; i <= n; i++) {
		if (visit[i] == 0 && graph[node][i] == 1)
			dfs(n, i, visit, graph);
	}
}

int main(void)
{
	int n, m, k;
	int graph[1001][1001] = {{0}}, visit[1001], count;
	int a, b, i, j;

	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}

	for (i = 0; i < k; i++) {
		for (j = 0; j < 1001; j++)
			visit[j] = 0;
		scanf("%d", &a);
		count = 0;
		visit[a] = 1;
		for (j = 1; j <= n; j++) {
			if (visit[j] == 0) {
				dfs(n, j, visit, graph);
				count++;
			}
		}
		printf("%d\n", count - 1);
	}
	return 0;
}
