/*
 * 设计思路：
 * 对于每次所给的点集
 * * 在点集中的点，循环判断是否两两相连
 *   * 若是，则为 Clique，
 *        * 遍历不在点集中的点，看是否有点和 Clique 中的点均相连
 *                * 若没有，则为 Maximal
 *                * 若有，则可以确定仅仅是 Clique
 *   * 否则，Not a Clique
 */

#include <stdio.h>

int main(void)
{
	int v[210][210];
	int nv, ne, m;
	int a, b, i, j;

	scanf("%d%d", &nv, &ne);
	for (i = 0; i < ne; i++) {
		scanf("%d%d", &a, &b);
		v[a][b] = 1;
		v[b][a] = 1;
	}
	int k, p[210], map[210] = {0};
	int clique, maximal;
	scanf("%d", &m);
	while (m--) {
		for (i = 0; i < 210; i++)
			map[i] = 0;
		scanf("%d", &k);
		for (i = 0; i < k; i++) {
			scanf("%d", &p[i]);
			map[p[i]] = 1;
		}

		clique = 1;
		maximal = 1;
		for (i = 0; i < k; i++) {
			if (clique == 0)
				break;
			for (j = i + 1; j < k; j++) {
				if (v[p[i]][p[j]] == 0) {
					clique = 0;
					break;
				}
			}
		}
		if (clique) {
			for (i = 1; i <= nv; i++) {
				if (maximal == 0)
					break;
				if (map[i] == 0) {
					for (j = 0; j < k; j++)
						if (v[p[j]][i] == 0)
							break;
					if (j == k)
						maximal = 0;
				}
			}
		}

		if (clique == 0)
			printf("Not a Clique\n");
		else if (maximal == 0)
			printf("Not Maximal\n");
		else
			printf("Yes\n");
	}
	return 0;
}
