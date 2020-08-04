/*
 * 设计思路：
 * 并查集
 * * 边读取数据，边合并集合
 * * 最后有几个集合，就有几颗树
 * * 对于每次查询，直接返回并查集结果
 */

#include <stdio.h>

int father[10010], rank[10010];

void makeset()
{
	int i;
	for (i = 0; i < 10010; i++) {
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
	int n, k, birdnum = 0, treenum = 0;
	int i, a, b;

	makeset();
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		if (k--) {
			scanf("%d", &a);
			birdnum = (birdnum > a ? birdnum : a);
		}
		while (k--) {
			scanf("%d", &b);
			birdnum = (birdnum > b ? birdnum : b);
			judge(a, b);
		}
	}
	for (i = 1; i <= birdnum; i++)
		if (getfather(i) == i)
			treenum++;
	printf("%d %d\n", treenum, birdnum);
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &a, &b);
		printf("%s\n", getfather(a) == getfather(b) ? "Yes" : "No");
	}

	return 0;
}
