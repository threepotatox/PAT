/*
 * 设计思路：
 * 排好序按要求输出
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct id{
	char str[14];
	char level[2];
	int room;
	int date;
	int num;
	int score;
};

int cmp(const void *a, const void *b)
{
	struct id *ida = (struct id*)a, *idb = (struct id*)b;
	if (ida->score != idb->score)
		return idb->score - ida->score;
	return strcmp(ida->str, idb->str);
}

int type1(struct id ids[], int n, int i);
int type2(struct id ids[], int n, int i);
int type3(struct id ids[], int n, int i);

int main(void)
{
	struct id ids[10000];
	int n, m, type;
	int i;
	char level[2];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s %d", ids[i].str, &ids[i].score);
		sscanf(ids[i].str, "%1s%3d%6d%3d", ids[i].level,
				&ids[i].room, &ids[i].date, &ids[i].num);
	}

	qsort(ids, n, sizeof(ids[0]), cmp);

	for (i = 0; i < m; i++) {
		scanf("%d", &type);
		if (type == 1)
			type1(ids, n, i);
		else if (type == 2)
			type2(ids, n, i);
		else if (type == 3)
			type3(ids, n, i);
	}

	return 0;
}

int type1(struct id ids[], int n, int i)
{
	char level[2];
	int f = 1, j;
	scanf("%1s", level);
	printf("Case %d: %d %c\n", i + 1, 1, level[0]);
	for (j = 0; j < n; j++)
		if (ids[j].level[0] == level[0]) {
			f = 0;
 			printf("%s %d\n", ids[j].str,ids[j].score);
		}
	if (f)
		puts("NA");
	return 0;
}

int type2(struct id ids[], int n, int i)
{
	int room, sum = 0, count = 0;
	int j, f = 1;

	scanf("%d", &room);
	printf("Case %d: %d %d\n", i + 1, 2, room);
	for (j = 0; j < n; j++)
		if (ids[j].room == room) {
			f = 0;
			count++;
			sum += ids[j].score;
		}
	if (f)
		puts("NA");
	else
		printf("%d %d\n", count, sum);

	return 0;
}

int type3(struct id ids[], int n, int i)
{
	int date, max = 0, rooms[1000] = {0};
	int f = 1, j;

	scanf("%d", &date);
	printf("Case %d: %d %06d\n", i + 1, 3, date);
	for (j = 0; j < n; j++)
		if (ids[j].date == date) {
  			f = 0;
			rooms[ids[j].room]++;
			if (max < rooms[ids[j].room])
     				max = rooms[ids[j].room];
		}
	if (f)
		puts("NA");
	else
		for (; max > 0; max--)
			for (j = 101; j < 1000; j++)
				if (rooms[j] == max)
  					printf("%d %d\n", j, max);

	return 0;
}
