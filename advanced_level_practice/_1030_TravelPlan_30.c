/*
 * 设计思路：
 * Dijksta 和 DFS
 * * Dijksta 求得 pre[] 数组
 * * DFS 遍历输出最短路径
 */

#include <stdio.h>
#include <limits.h>

int dfs(int d, int s, int pre[])
{
	if (d == s) {
		printf("%d", d);
		return 0;
	} else {
		dfs(pre[d], s, pre);
		printf(" %d", d);
	}
	return 0;
}

int main(void)
{
	int n, m, s, d;
	int gdis[505][505], gcost[505][505];
	int dis[505], cost[505], pre[505] = {0}, visit[505] = {0};
	int i, j, u, v, minn;
	for (i = 0; i < 505; i++)
		dis[i] = INT_MAX;
	for (i = 0; i < 505; i++)
		cost[i] = INT_MAX;
	for (i = 0; i < 505; i++)
		for (j = 0; j < 505; j++)
			gdis[i][j] = INT_MAX;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	for (i = 0; i < m; i++) {
		int a, b, e, f;
		scanf("%d %d %d %d", &a, &b, &e, &f);
		gdis[a][b] = gdis[b][a] = e;
		gcost[a][b] = gcost[b][a] = f;
	}

	dis[s] = 0;
	cost[s] = 0;
	for (i = 0; i < n; i++) {
		u = -1, minn = INT_MAX;
		for (j = 0; j < n; j++) {
			if (visit[j] == 0 && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)
			break;
		visit[u] = 1;
		for (v = 0; v < n; v++) {
			if (visit[v] == 0 && gdis[u][v] != INT_MAX) {
				if (dis[v] > dis[u] + gdis[u][v]) {
					dis[v] = dis[u] + gdis[u][v];
					cost[v] = cost[u] + gcost[u][v];
					pre[v] = u;
				} else if (dis[v] == dis[u] + gdis[u][v] && cost[v] > cost[u] + gcost[u][v]) {
					cost[v] = cost[u] + gcost[u][v];
					pre[v] = u;
				}
			}
		}
	}

	dfs(d, s, pre);
	printf(" %d %d", dis[d], cost[d]);

	return 0;
}
