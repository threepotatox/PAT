/*
 * 设计思路：
 * 并查集
 * * 读取数据时，就进行并查集的合并
 * * 遍历所有人，计算每个家庭的信息
 * * 把家庭信息排序，输出
 */

#include <stdio.h>

struct data {
	int id, fid, mid;
};

struct node {
	int id, num;
	double sets, area;
};

int father[10010];

void makeset()
{
	int i;
	for (i = 0; i < 10010; i++)
		father[i] = i;
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
	if (fx > fy)
		father[fx] = fy;
	else
		father[fy] = fx;
}

int cmp(const void *a, const void *b)
{
	struct node *p = *((struct node **)a), *q = *((struct node **)b);
	double temp = p->area - q->area;
	if (temp > 0)
		return -1;
	else if (temp < 0)
		return 1;

	return p->id - q->id;
}

int main(void)
{
	int n;
	int people[10010] = {0}, id, f, m, k, c;
	double estate[10010][2] = {0};
	struct node family[10010] = {0};
	struct node *result[10010] = {0};
	int i, cnt = 0;

	makeset();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &id, &f, &m, &k);
		people[id] = 1;
		if (f != -1) {
			judge(id, f);
			people[f] = 1;
		}
		if (m != -1) {
			judge(id, m);
			people[m] = 1;
		}
		while (k > 0) {
			scanf("%d", &c);
			judge(id, c);
			people[c] = 1;
			k--;
		}
		scanf("%lf%lf", &estate[id][0], &estate[id][1]);
	}

	for (i = 0; i < 10010; i++) {
		if (people[i]) {
			int temp = getfather(i);
			family[temp].num++;
			family[temp].sets += estate[i][0];
			family[temp].area += estate[i][1];
			if (temp == i) {
				family[temp].id = temp;
				result[cnt++] = &family[temp];
			}
		}
	}
	for (i = 0; i < cnt; i++) {
		result[i]->sets /= result[i]->num;
		result[i]->area /= result[i]->num;
	}

	qsort(result, cnt, sizeof(result[0]), cmp);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
		printf("%04d %d %.3lf %.3lf\n", result[i]->id, result[i]->num, result[i]->sets, result[i]->area);

	return 0;
}
