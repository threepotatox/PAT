/*
 * 设计思路：
 * 相当于每个窗口只容纳一人，只需为每个窗口维护一个结束时间
 * 1. 读取数据，根据到达时间排序
 * 2. 遍历 17:00 之前到达的顾客，查询完成时间最早的窗口，则：
 *     * 顾客到达时间早于此窗口结束时间：两者之差累加到等待时间，此窗口结束时间累加顾客业务时间
 *     * 顾客到达时间晚于此窗口结束时间：顾客无等待时间，此窗口结束时间更新为顾客到达时间加业务时间
 */

#include <stdio.h>

struct customer {
	int start;
	int time;
};

int cmp(const void *a, const void *b)
{
	struct customer *c1 = (struct customer *)a;
	struct customer *c2 = (struct customer *)b;
	return c1->start - c2->start;
}

int main(void)
{
	int n, k;
	int hh, mm, ss;
	int wait = 0, endtime[100] = {0};
	struct customer customers[10000], *p;
	int i, j;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &customers[i].time);
		customers[i].start = ((hh - 8) * 60 + mm ) * 60 + ss;
		customers[i].time *= 60;
	}

	qsort(customers, n, sizeof(struct customer), cmp);

	for (i = 0; (customers[i].start <= (17 - 8) * 3600) && (i < n); i++) {
		p = customers + i;

		int num = 0;
		for (j = 0; j < k; j++)
			if (endtime[j] < endtime[num])
				num = j;

		if (p->time > 3600)
			p->time = 3600;


		if(p->start < endtime[num]) {
			wait += endtime[num] - p->start;
			endtime[num] += p->time;
		} else {
			endtime[num] = p->start + p->time;
		}
	}

	if (i)
		printf("%.1f", wait / 60.0 / i);
	else
		printf("0.0");

	return 0;
}
