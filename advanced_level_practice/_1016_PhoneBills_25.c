/*
 * 设计思路：
 * * 输入数据，先按照客户名排序，再按照时间排序
 * * 遍历数据，前后客户名相同且状态分别为 on-line 和 off-line，为合格数据
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct record {
	char name[21];
	int month, day, hour, min, time, state;
};

int cmp(const void *a, const void *b)
{
	struct record *c1 = (struct record *)a, *c2 = (struct record *)b;
	return strcmp(c1->name, c2->name) ?
	       strcmp(c1->name, c2->name) : c1->time - c2->time;
}

int charge(struct record *p1, struct record *p2, int toll[])
{
	int bill = 0, start = p1->time, end = p2->time, h, time1, time2;

	for (time1 = start; time1 < end; time1 = time2) {
		time2 = (time1 / 60 + 1) * 60;
		h = time1 / 60 % 24;
		bill += ((time2 > end ? end : time2) - time1) * toll[h];
	}

	return bill;
}

int main(void)
{
	int n, toll[24];
	struct record records[1001] = {0};
	char state[9];
	int i;

	for (i = 0; i < 24; i++)
		scanf("%d", toll + i);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s",
				records[i].name,
				&records[i].month, &records[i].day, &records[i].hour, &records[i].min,
				state);
		records[i].time = (records[i].day * 24 + records[i].hour) * 60 + records[i].min;
		records[i].state = strcmp(state, "on-line") ? 0 : 1;
	}

	qsort(records, n, sizeof(struct record), cmp);

	int bill = 0, bills = 0;
	for (i = 1; i <= n; i++) {
				printf("Total amount: $%.2f\n", bills * 1e-2);
			bills = 0;
		} else if (records[i - 1].state == 1 && records[i].state == 0) {
			if (bills == 0)
				printf("%s %02d\n", records[i].name, records[i].month);
			bill = charge(&records[i - 1], &records[i], toll);
			bills += bill;

			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
					records[i - 1].day, records[i - 1].hour, records[i - 1].min,
					records[i].day, records[i].hour, records[i].min,
					records[i].time - records[i - 1].time,
					bill * 1e-2);
		}
	}

	return 0;
}
