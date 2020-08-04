/*
 * 设计思路：
 * 按照题目要求，用两个 Dijkstra 算法分别求最短路径和最快路径
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, m, start, end, shortest[2];
int vt[510][510], vw[510][510];

int visit[510], dis[510], predis[510], time[510], pretime[510];
int wshortest[510], wcnt, tshortest[510], tcnt;
void dijkstra_w()
{
	int i, j, u, v, min;
	for (j = 0; j < n; j++) {
		visit[j] = 0;
		dis[j] = INT_MAX;
		//time[j] = INT_MAX;
	}
	dis[start] = 0;
	for (i = 0; i < n; i++) {
		u = -1;
		min = INT_MAX;
		for (j = 0; j < n; j++) {
			if (visit[j] == 0 && dis[j] < min) {
				u = j;
				min = dis[j];
			}
		}
		if (u == -1)
			break;
		visit[u] = 1;
		for (v = 0; v < n; v++) {
			if (visit[v] == 0 && vw[u][v]) {
				if (vw[u][v] + dis[u] < dis[v]) {
					dis[v] = vw[u][v] + dis[u];
					predis[v] = u;
					time[v] = time[u] + vt[u][v];
				} else if (vw[u][v] + dis[u] == dis[v] && time[v] > time[u] + vt[u][v]) {
					time[v] = time[u] + vt[u][v];
					predis[v] = u;
				}
			}
		}
	}
}

void dijkstra_t()
{
	int num[510];
	int i, j, u, v, min;
	for (j = 0; j < n; j++) {
		visit[j] = 0;
		time[j] = INT_MAX;
	}
	time[start] = 0;
	for (i = 0; i < n; i++) {
		u = -1;
		min = INT_MAX;
		for (j = 0; j < n; j++) {
			if (visit[j] == 0 && time[j] < min) {
				u = j;
				min = time[j];
			}
		}
		if (u == -1)
			break;
		visit[u] = 1;
		for (v = 0; v < n; v++) {
			if (visit[v] == 0 && vt[u][v]) {
				if (vt[u][v] + time[u] < time[v]) {
					time[v] = vt[u][v] + time[u];
					pretime[v] = u;
					num[v] = num[u] + 1;
				} else if (vt[u][v] + time[u] == time[v] && num[v] > num[u] + 1) {
					num[v] = num[u] + 1;
					pretime[v] = u;
				}
			}
		}
	}
}

void dfs_w(int v)
{
	wshortest[wcnt++] = v;
	if (v == start)
		return ;
	dfs_w(predis[v]);
}

void dfs_t(int v)
{
	tshortest[tcnt++] = v;
	if (v == start)
		return ;
	dfs_t(pretime[v]);
}

int comp()
{
	if (wcnt != tcnt)
		return 0;
	int i;
	for (i = 0; i < wcnt; i++)
		if (wshortest[i] != tshortest[i])
			return 0;
	return 1;
}

void out_printf(int *a, int cnt)
{
	int i;
	printf("%d", a[cnt - 1]);
	for (i = cnt - 2; i >= 0; i--)
		printf(" -> %d", a[i]);
}

int main(void)
{
	int a, b, c, d, e;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		vw[a][b] = d;
		vt[a][b] = e;
		if (c == 0) {
			vw[b][a] = d;
			vt[b][a] = e;
		}
	}
	scanf("%d%d", &start, &end);

	dijkstra_w();
	dfs_w(end);
	dijkstra_t();
	dfs_t(end);
	if (comp()) {
		printf("Distance = %d; Time = %d: ", dis[end], time[end]);
		out_printf(wshortest, wcnt);
	} else {
		printf("Distance = %d: ", dis[end]);
		out_printf(wshortest, wcnt);
		puts("");
		printf("Time = %d: ", time[end]);
		out_printf(tshortest, tcnt);
	}
	
	return 0;
}
