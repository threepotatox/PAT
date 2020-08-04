/*
 * 设计思路：
 * Dijkstra 计算最短路径
 * * 对 M 个加油站依次计算 Dijkstra 最短路径
 * * 判断此加油站的服务范围覆盖，最近村庄最远，平均距离最小，编号最小
 * * 输出最终编号
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int c2i(char *a, int n)
{
	if (a[0] == 'G')
		return atoi(a + 1) + n;
	return
		atoi(a);
}

int e[1020][1020] = {0};
int dis[1020], visit[1020];

void dijkstra(int start, int n)
{
	int i, j, u, v, min;
	for (j = 0; j <= n; j++) {
		dis[j] = INT_MAX;
		visit[j] = 0;
	}
	dis[start] = 0;
	for (i = 0; i < n; i++) {
		u = -1;
		min = INT_MAX;
		for (j = 1; j <= n; j++) {
			if (visit[j] == 0 && dis[j] < min) {
				u = j;
				min = dis[j];
			}
		}
		if (u == -1)
			break;
		visit[u] = 1;
		for (v = 1; v <= n; v++)
			if (!visit[v] && e[u][v] && dis[u] + e[u][v] < dis[v])
				dis[v] = dis[u] + e[u][v];
	}
}

int main(void)
{
	int n, m, k, ds, station = -1;
	double mindis = -1.0, avgdis = INT_MAX * 1.0, mindis_now, avgdis_now;
	char s1[5], s2[5];
	int i, j, u, v, flag;

	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for (i = 0; i < k; i++) {
		scanf("%s%s%d", s1, s2, &j);
		u = c2i(s1, n);
		v = c2i(s2, n);
		e[u][v] = j;
		e[v][u] = j;
	}
	for (i = n + 1; i <= n + m; i++) {
		dijkstra(i, n + m);
		mindis_now = INT_MAX * 1.0;
		avgdis_now = 0.0;
		flag = 1;
		for (j = 1; j <= n && flag; j++) {
			if (dis[j] <= ds) {
				mindis_now = mindis_now < dis[j] * 1.0 ? mindis_now : dis[j] * 1.0;
				avgdis_now += dis[j] * 1.0;
			} else {
				flag = 0;
			}
		}
		avgdis_now /= n;
		if (flag && (mindis_now > mindis || (mindis_now == mindis && avgdis_now < avgdis))) {
			station = i;
			mindis = mindis_now;
			avgdis = avgdis_now;
		}
	}
	if (station != -1)
		printf("G%d\n%.1lf %.1lf", station - n, mindis, avgdis);
	else
		printf("No Solution");
	return 0;
}
