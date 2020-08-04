/*
 * 设计思路：
 * Dijkstar 算法求出题目要求的最短路径，DFS 输出路径
 * * 需要用两个数组，映射城市名和编号
 * * 最短路径要求，路径最短，幸福值最大，平均幸福值最大
 */

#include <stdio.h>
#include <limits.h>

int c2i(char *a)
{
	return (a[0] - 65) * 26 * 26 + (a[1] - 65) * 26 + (a[2] - 65);
}

void dfs(int v, int pre[], char city[][4])
{
	if (v == 0) {
		printf("%s", city[v]);
		return ;
	}
	dfs(pre[v], pre, city);
	printf("->%s", city[v]);
}

int e[200][200] = {0}, happy[200], dis[200], happiness[200], pre[200], prenum[200], pathnum[200], visit[200] = {0};
char s[4], s2[4], city[200][4];
int city2int[26 * 26 * 26];

int main(void)
{
	int n, k, i, j, u, v, min;
	int start, end;

	scanf("%d%d%s", &n, &k, city[0]);
	getchar();
	city2int[c2i(city[0])] = 0;
	for (i = 1; i < n; i++) {
		scanf("%s%d", city[i], &j);
		getchar();
		city2int[c2i(city[i])] = i;
		happy[i] = j;
	}
	for (i = 0; i < k; i++) {
		scanf("%s%s%d", s, s2, &j);
		getchar();
		u = city2int[c2i(s)];
		v = city2int[c2i(s2)];
		e[u][v] = j;
		e[v][u] = j;
	}
	start = 0;
	end = city2int[c2i("ROM")];
	for (i = 1; i < n; i++)
		dis[i] = INT_MAX;
	dis[0] = 0;

	pathnum[start] = 1;
	happiness[start] = 0;
	prenum[start] = 0;
	pre[start] = 0;
	while (!visit[end]) {
		u = -1;
		min = INT_MAX;
		for (i = 0; i < n; i++) {
			if (visit[i] == 0 && dis[i] < min) {
				u = i;
				min = dis[i];
			}
		}
		if (u == -1)
			break;
		visit[u] = 1;
		for (v = 0; v < n; v++) {
			if (!visit[v] && e[u][v]) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					pathnum[v] = pathnum[u];
					happiness[v] = happiness[u] + happy[v];
					prenum[v] = prenum[u] + 1;
					pre[v] = u;
				} else if (dis[u] + e[u][v] == dis[v]) {
					pathnum[v] += pathnum[u];
					if (happiness[u] + happy[v] > happiness[v]
					|| (happiness[u] + happy[v] == happiness[v] && prenum[u] + 1 < prenum[v])) {
						happiness[v] = happiness[u] + happy[v];
						prenum[v] = prenum[u] + 1;
						pre[v] = u;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", pathnum[end], dis[end], happiness[end], happiness[end] /  prenum[end]);
	dfs(end, pre, city);

	return 0;
}
