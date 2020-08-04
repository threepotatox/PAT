/*
 * 设计思路：
 * * 保存每个节点的入度
 * * 当到达某节点时，将此节点能到达的节点入度减 1
 * * 遍历所给序列节点时，有入度不为 0 的节点，说明不是拓扑排序
 */

#include <stdio.h>

int graph[1010][1010] = {0}, cnt[1010] = {0};

int main(void)
{
	int n, m, k;
	int degree[1010] = {0};
	int i, j, a, b;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		graph[a][cnt[a]] = b;
		cnt[a]++;
		degree[b]++;
	}
	int t, space = 0, temp[1010];
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		for (j = 1; j <= n; j++)
			temp[j] = degree[j];
		for (j = 0; j < n; j++) {
			scanf("%d", &a);
			if (temp[a] != 0) {
				printf("%s%d", space == 1 ? " ": "", i);
				space = 1;
				for (j++; j < n; j++)
					scanf("%d", &a);
				break;
			}
			for (t = 0; t < cnt[a]; t++)
				temp[graph[a][t]]--;
		}
	}

	return 0;
}
