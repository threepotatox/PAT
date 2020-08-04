/*
 * 设计思路：
 * 并查集
 * * 社交圈是人组成的，爱好仅是判断两人是否在同一社交圈的媒介
 * * hobby[] 数组记录当前爱好有无人喜欢
 *   * 若还没有，自己占据此爱好，当作此社交圈的祖先
 *   * 若有人，则把自己加入此社交圈
 * * 对每个人进行遍历，记录组成了多少社交圈，和每个社交圈的人数
 */

#include <stdio.h>

int cmp(const void *a, const void *b)
{
	return *((int *)b) - *((int *)a);
}

int father[1010], rank[1010];

void makeset()
{
	int i;
	for (i = 0; i < 1010; i++) {
		father[i] = i;
		rank[i] = 0;
	}
}

int getfather(int v)
{
	if (father[v] == v)
		return v;
	father[v] = getfather(father[v]);
	return father[v];
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
	int n;
	int hobby[1010] = {0}, result[1010] = {0};
	int i, j, k, a;

	makeset();
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d:", &k);
		while (k--) {
			scanf("%d", &a);
			if (hobby[a] == 0)
				hobby[a] = i;
			else
				judge(hobby[a], i);
		}
	}
	for (i = 1; i <= n; i++)
		result[getfather(i)]++;
	qsort(result + 1, n, sizeof(result[0]), cmp);
	for (i = 1; i <= n && result[i] > 0; i++)
		;
	printf("%d\n", i - 1);
	for (j = 1; j < i; j++)
		printf("%s%d", j > 1 ? " " : "", result[j]);
	return 0;
}
