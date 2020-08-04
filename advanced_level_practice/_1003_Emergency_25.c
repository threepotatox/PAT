/*设计思路：
 * Dijkstra 算法
 * 1. 当节点出现最短路径，更新节点最短路径，最短路径数目，及救援队数目之和
 * 2. 当节点最短路径未改变，累加节点最短路径数目，更新救援队数目之和
 */

#include <stdio.h>
#include <limits.h>

int main()
{
	int n, m, c1, c2;
	int e[510][510], weight[510], dis[510], num[510], w[510];
	int visit[510] = {0};
	int i, j, u, v, minn;


	for (i = 0; i < 510; i++)
		dis[i] = INT_MAX;
	for (i = 0; i < 510; i++)
		for (j = 0; j < 510; j++)
			e[i][j] = INT_MAX;
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &j, &u, &v);
		e[j][u] = v;
		e[u][j] = v;
	}

	dis[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;
	for (i = 0; i < n; i++) {
		u = -1;
		minn = INT_MAX;
		for (j = 0; j < n; j++) {
			if (visit[j] == 0 && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = 1;
		for (v = 0; v < n; v++) {
			if (visit[v] == 0 && e[u][v] != INT_MAX) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				} else if (dis[u] + e[u][v] == dis[v]) {
					num[v] = num[v] + num[u];
					if (w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
				}
			}
		}
	}

	printf("%d %d", num[c2], w[c2]);

	return 0;
}
