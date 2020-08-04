/*
 * 设计思路：
 * 按照车牌号字典序从小到大，时间从小到大对所有车进行排序
 * * 遍历且仅记录满足配对要求的每对记录
 * * 遍历过程中记录每辆车停留的时间
 *   * 同一辆车会有多次满足配对要求的记录，所以对于停留时间要判断累加
 *   * 并记录最大值和车牌号
 * * 利用满足配对要求的记录，按秒记录每个时间点在校园内的车辆数目，查询时，直接返回对应时间的数目即可
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char id[10];
	int time;
	int state;
};

int cmp1(const void *a, const void *b)
{
	struct node *x = (struct node *)a, *y = (struct node *)b;
	if (strcmp(x->id, y->id) != 0)
		return strcmp(x->id, y->id);
	return x->time - y->time;
}

int cmp2(const void *a, const void *b)
{
	return (*((struct node **)a))->time - (*((struct node **)b))->time;
}

int main(void)
{
	int n, k;
	int i, j, hh, mm, ss, tempint;
	struct node record[10000], *recordtime[10000];
	char tempstr[5], maxid[10000][10];
	int sum[24 * 3600], cnt, maxtime, maxcnt;

	scanf("%d%d\n", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s %d:%d:%d %s\n", record[i].id, &hh, &mm, &ss, tempstr);
		tempint = hh * 3600 + mm * 60 + ss;
		record[i].time = tempint;
		record[i].state = tempstr[0] == 'i' ? 1 : -1;
	}
	qsort(record, n, sizeof(record[0]), cmp1);
	for (i = 1, j = 0; i < n; i++) {
		if (strcmp(record[i - 1].id, record[i].id) == 0 && record[i - 1].state == 1 && record[i].state == -1) {
			record[j] = record[i - 1];
			recordtime[j] = &record[j];
			j++;
			record[j] = record[i];
			recordtime[j] = &record[j];
			j++;

			if (j == 2) {
				tempint = record[j - 1].time - record[j - 2].time;
				maxtime = tempint;
				strcpy(maxid[0], record[j - 1].id);
				maxcnt = 1;
			} else if (j > 2) {
				if (strcmp(record[j - 1].id, record[j - 3].id) == 0) {
					tempint += record[j - 1].time - record[j - 2].time;
				} else {
					tempint = record[j - 1].time - record[j - 2].time;
				}
				if (maxtime < tempint) {
					maxtime = tempint;
					strcpy(maxid[0], record[j - 1].id);
					maxcnt = 1;
				} else if (maxtime == tempint) {
					strcpy(maxid[maxcnt], record[j - 1].id);
					maxcnt++;
				}
			}
		}
	}
	n = j;
	qsort(recordtime, n, sizeof(recordtime[0]), cmp2);
	for (i = 0, j = 0, cnt = 0; i < 24 * 3600; i++) {
		while (j < n && recordtime[j]->time <= i) {
			if (recordtime[j]->state == 1)
				cnt++;
			else
				cnt--;
			j++;
		}
		sum[i] = cnt;
	}

	for (i = 0; i < k; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		tempint = hh * 3600 + mm * 60 + ss;
		printf("%d\n", sum[tempint]);
	}
	for (i = 0; i < maxcnt; i++)
		printf("%s ", maxid[i]);
	printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);

	return 0;
}
