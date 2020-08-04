/*
 * 设计思路：
 * 1079
 *
 * 价格仅和叶节点层数有关，所以利用并查集的思想，记录每个节点的父节点，以递推出叶节点的层数
 * * level[v] = get_level(father[v]) + 1，要用数组 level 记录层级信息，不记录的话每次都查询到根节点，会超时
 * * 根节点 level[0] = 0
 * * 注意根节点是 -1 表示的，查询根节点 0 的层数时会询问 -1 节点，此时把 -1 节点看作根节点的父节点，返回 -1
 */

#include <stdio.h>
#include <math.h>

double p, r;
int father[100010], level[100010], root[100010];

int get_level(int v)
{
	if (v == -1)
		return -1;
	if (level[v] > 0)
		return level[v];
	level[v] = get_level(father[v]) + 1;
	return level[v];
}

int main(void)
{
	int n;
	int f, max = 0, cnt = 0;
	int i, temp;

	scanf("%d%lf%lf", &n, &p, &r);
	for (i = 0; i < n; i++)
		father[i] = -2;
	r = r / 100.0;
	for (i = 0; i < n; i++) {
		scanf("%d", &f);
		father[i] = f;
		root[f] = 1;
	}
	for (i = 0; i < n; i++) {
		if (root[i] == 0) {
			temp = get_level(i);
			if (temp > max) {
				max = temp;
				cnt = 1;
			} else if (temp == max) {
				cnt++;
			}
		}
	}
	printf("%.2lf %d", pow(1 + r, max) * p, cnt);
	return 0;
}
