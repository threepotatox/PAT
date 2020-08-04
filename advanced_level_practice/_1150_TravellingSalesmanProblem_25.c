/*
 * 设计思路：
 * * 判断是否是 cycle，能否构成回路
 * * 判读是否是 simple cycle，构成的回路，仅首尾节点相同
 * * 判断是否是 TS，路径节点个数等于图节点个数 N + 1，因为首尾节点均是起点
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
	int n, m, k;
	int v[210][210] = {0};
	int minindex = -1, mindis = INT_MAX;
	int a, b, c, i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a][b] = v[b][a] = c;
	}
	scanf("%d", &k);
	int p[2010], t, dis, cycle, simple, na;
	int map[210], cnt;
	for (j = 1; j <= k; j++) {
		for (i = 0; i < 210; i++)
			map[i] = 0;
		cnt = 0;
		dis = 0;
		cycle = 1;
		simple = 1;
		na = 0;
		scanf("%d", &t);
		for (i = 0; i < t; i++) {
			scanf("%d", &p[i]);
			if (i > 0) {
				na = (v[p[i - 1]][p[i]] == 0 ? 1 : na);
				dis += v[p[i - 1]][p[i]];
				if (map[p[i]] == 0) {
					map[p[i]] = 1;
					cnt++;
				}
			}
		}
		cycle = (na == 0 && p[0] == p[t - 1] && cnt == n);
		if (cycle == 1 && t == n + 1)
			simple = 1;
		else
			simple = 0;

		printf("Path %d: ", j);
		if (na)
			printf("NA");
		else
			printf("%d", dis);
		printf(" (%s)\n", cycle ? (simple ? ("TS simple cycle") : ("TS cycle")) : ("Not a TS cycle"));
		if (cycle && dis < mindis) {
			mindis = dis;
			minindex = j;
		}
	}
	printf("Shortest Dist(%d) = %d", minindex, mindis);
	return 0;
}
