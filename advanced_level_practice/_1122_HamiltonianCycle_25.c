/*
 * 设计思路：
 * 哈密顿环必须同时满足以下条件：
 * 1. 构成一个环路
 * 2. 经过图中的所有节点
 * 3. 除首尾节点为同一节点出现两次，其他节点只能出现一次
 *
 * 针对其特点，写一个判断函数即可
 */

#include <stdio.h>

int v[210][210];

int judge(int *p, int cnt, int n)
{
	if (cnt != n + 1 || p[0] != p[cnt - 1])
		return 0;
	int i, j;
	for (i = 1; i < cnt; i++)
		for (j = i + 1; j < cnt; j++)
			if (p[i] == p[j])
				return 0;
	for (i = 1; i < cnt; i++)
		if (v[p[i -1]][p[i]] == 0)
			return 0;
	return 1;
}

int main(void)
{
	int n, m, k;
	int i, a, b;
	int p[410];

	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		v[a][b] = 1;
		v[b][a] = 1;
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &m);
		for (i = 0; i < m; i++)
			scanf("%d", &p[i]);
		printf("%s\n", judge(p, m, n) ? "YES" : "NO");
	}
	return 0;
}
