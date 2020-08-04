/*
 * 设计思路：
 * * 记录下 M 条边两边的端点号
 * * 对每个集合的询问，遍历所有边是否满足端点至少有一个在集合中
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, m, k;
	int e[10010][2], ver[10010];
	int i, v, a;

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d%d", &e[i][0], &e[i][1]);
	
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &v);
		memset(ver, 0, sizeof(ver));
		while (v--) {
			scanf("%d", &a);
			ver[a] = 1;
		}
		for (i = 0; i < m; i++)
			if (ver[e[i][0]] == 0 && ver[e[i][1]] == 0)
				break;
		printf("%s\n", i == m ? "Yes" : "No");
	}
	return 0;
}
