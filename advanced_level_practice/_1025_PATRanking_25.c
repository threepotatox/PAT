/*
 * 设计思路：
 * * 输入过程中，先每个考场排序，得到考场排名
 * * 再进行一次整体排序，得到总排名
 * * 分数相同，按学号从小到大排
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu {
	char reg[14];
	int loc, score, rank, lrank;
};

int cmp(const void *a, const void *b)
{
	struct stu *p1 = (struct stu*)a, *p2 = (struct stu*)b;
	if (p1->score != p2->score)
		return p2->score - p1->score;
	else
		return strcmp(p1->reg, p2->reg);
}

int main(void)
{
	int n, k;
	struct stu stus[30000] = {0}, *q = stus;
	int loc, i;

	scanf("%d", &n);
	for (loc = 0; loc < n; loc++) {
		scanf("%d", &k);
		for (i = 0; i < k; i++) {
			scanf("%s %d", q->reg, &q->score); 
			q->loc = loc + 1;
			q++;
		}

		qsort(q - k, k, sizeof(struct stu), cmp);
		(q - k)->lrank = 1;
		for (i = k - 1; i > 0; i--) {
			(q - i)->lrank = (q - i)->score == ((q - i) - 1)->score ?
				((q - i) - 1)->lrank : k - i + 1;
		}
	}

	qsort(stus, q - stus, sizeof(struct stu), cmp);
	stus[0].rank = 1;
	for (i = 1; i < (q - stus); i++) {
		stus[i].rank = stus[i].score == stus[i - 1].score ?
			stus[i - 1].rank : i + 1;
	}

	printf("%ld\n", q - stus);
	for (i = 0; i < (q - stus); i++)
		printf("%s %d %d %d\n", stus[i].reg, stus[i].rank, stus[i].loc, stus[i].lrank);

	return 0;
}
