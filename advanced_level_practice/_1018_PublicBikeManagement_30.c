/*
 * 设计思路：
 * Dijkstra 求所有最短路径，DFS 选择最短路径中的最优值
 * * 邻接链表（结构数组模拟实现），存储节点最短路径的前驱节点
 * * DFS 遍历所有最短路径，过程中记录最优路径
 */

#include <stdio.h>
#include <limits.h>

struct node {
	int q[510];
	int c;
};

int minneed = INT_MAX, minback = INT_MAX;
struct node path = {0}, temppath = {0};
int cmax, n, sp, m;
int e[510][510], weight[510], dis[510];
int visit[510] = {0};
struct node pre[510] = {0};

void dfs(int v)
{
	temppath.q[temppath.c] = v;
	temppath.c++;
	if (v == 0) {
		int need = 0, back = 0, i;
		for (i = temppath.c - 1; i >= 0; i--) {
			int id = temppath.q[i];
			if (weight[id] > 0) {
				back += weight[id];
			} else {
				if (back > (0 - weight[id])) {
					back += weight[id];
				} else {
					need += ((0 - weight[id]) - back);
					back = 0;
				}
			}
		}
		if (need < minneed) {
			minneed = need;
			minback = back;
			path = temppath;
		} else if (need == minneed && back < minback) {
			minback = back;
			path = temppath;
		}
		temppath.c--;
		return ;
	}
	int i;
	for (i = 0; i < pre[v].c; i++)
		dfs(pre[v].q[i]);
	temppath.c--;
}

int main(void)
{
	int i, j, u, v, minn;

	for (i = 0; i < 510; i++)
		dis[i] = INT_MAX;
	for (i = 0; i < 510; i++)
		for (j = 0; j < 510; j++)
			e[i][j] = INT_MAX;
	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] -= (cmax / 2);
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &j);
		e[u][v] = j;
		e[v][u] = j;
	}

	dis[0] = 0;
	for (i = 0; i <= n; i++) {
		u = -1;
		minn = INT_MAX;
		for (j = 0; j <= n; j++) {
			if (visit[j] == 0 && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = 1;
		for (v = 0; v <= n; v++) {
			if (visit[v] == 0 && e[u][v] != INT_MAX) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].c = 0;
					pre[v].q[pre[v].c] = u;
					pre[v].c++;
				} else if (dis[v] == dis[u] + e[u][v]) {
					pre[v].q[pre[v].c] = u;
					pre[v].c++;
				}
			}
		}
	}

	dfs(sp);

	printf("%d 0", minneed);
	for (i = path.c - 2; i >= 0; i--)
		printf("->%d", path.q[i]);
	printf(" %d", minback);

	return 0;
}
