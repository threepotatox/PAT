/*
 * 设计思路：
 * 关键词：欧拉图，并查集
 *
 * 先用并查集判断是否为连通图，若是连通图再继续判断欧拉图
 * 1. Eulerian（欧拉图）：连通图，每个节点度为偶数
 * 2. Semi-Eulerian（半欧拉图）：连通图，只有两个节点度为奇数，其他均为偶数
 * 3. Non-Eulerian：既不是欧拉图也不是半欧拉图
 */

#include <stdio.h>

int father[510], rank[510];

int makeset()
{
	int i;
	for (i = 0; i < 510; i++) {
		father[i] = i;
		rank[i] = 0;
	}
}

int getfather(int v)
{
	if (father[v] == v)
		return v;
	else {
		father[v] = getfather(father[v]);
		return father[v];
	}
}

void judge(int x, int y)
{
	int fx = getfather(x);
	int fy = getfather(y);

	if (rank[fx] > rank[fy]) {
		father[fy] = fx;
	} else {
		father[fx] = fy;
		if (rank[fx] == rank[fy])
			rank[fy]++;
	}
}

int main(void)
{
	int degree[510] = {0};
	int n, m;
	int i, a, b, set = 0, cnt = 0;

	scanf("%d%d", &n, &m);
	makeset();
	while (m--) {
		scanf("%d%d", &a, &b);
		degree[a]++;
		degree[b]++;
		judge(a, b);
	}
	for (i = 1; i <= n; i++) {
		printf("%s%d", i > 1 ? " " : "", degree[i]);
		if (getfather(i) == i)
			set++;
		if(degree[i] % 2 == 1)
			cnt++;
	}
	if (set == 1) {
		if (cnt == 0)
			printf("\nEulerian");
		else if (cnt == 2)
			printf("\nSemi-Eulerian");
		else
			printf("\nNon-Eulerian");
	} else {
		printf("\nNon-Eulerian");
	}
	
	return 0;
}
