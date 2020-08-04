/*
 * 设计思路：
 * 1090
 *
 * 价格仅和叶节点层数有关，所以利用并查集的思想，记录每个节点的父节点，以递推出叶节点的层数
 * * level[v] = get_level(father[v]) + 1，要用数组 level 记录层级信息，不记录的话每次都查询到根节点，会超时
 * * 根节点 level[0] = 0
 */

#include <stdio.h>
#include <math.h>

double p, r;
int father[100010], level[100010], retailer[100010];

int get_level(int v)
{
	if (v == 0)
		return 0;
	if (level[v] > 0)
		return level[v];
	level[v] = get_level(father[v]) + 1;
	return level[v];
}

int main(void)
{
	int n, k, c;
	int i, j;
	int temp, min = 999999, cnt = 0;

	scanf("%d%lf%lf", &n, &p, &r);
	r = r / 100.0;
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			retailer[i] = 1;
		} else {
			for (j = 0; j < k; j++) {
				scanf("%d", &c);
				father[c] = i;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (retailer[i] > 0) {
			temp = get_level(i);
			if (temp < min) {
				min = temp;
				cnt = 1;
			} else if (temp == min) {
				cnt++;
			}
		}
	}
	printf("%.4lf %d", pow(1 + r, min) * p, cnt);
	return 0;
}
