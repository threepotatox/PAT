/*
 * 设计思路：
 * 排序题，按照题目排序输出即可
 * * 只要有一题编译通过，此考生即可参与排名，
 * * 可以参与排名，但有编译未通过的题目，视为 0 分记录
 * * 输入数据时，`-` 代表编译未通过，而输出数据时 `-` 代表未提交
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int rank, id, total, perfect, isshow;
	int score[6], notcompiler[6];
};

struct node stu[10000];

int max(int a, int b)
{
	return a > b ? a : b;
}

int cmp(const void *a, const void *b)
{
	struct node *p = (struct node *)a, *q = (struct node *)b;
	if (p->total != q->total)
		return q->total - p->total;
	else if (p->perfect != q->perfect)
		return q->perfect - p->perfect;
	else
		return p->id - q->id;

}

int main(void)
{
	int n, k, m, id, num, score, perfect[6];
	int i, j;

	scanf("%d%d%d", &n, &k, &m);
	for (i = 1; i <= k; i++)
		scanf("%d", &perfect[i]);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &id, &num, &score);
		stu[id].id = id;
		stu[id].score[num] = max(stu[id].score[num], score);
		if (score == -1 && stu[id].notcompiler[num] <= 0) {
			stu[id].notcompiler[num] = -1;
		} else {
			stu[id].isshow = 1;
			stu[id].notcompiler[num] = 1;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			stu[i].total += stu[i].score[j];
			if (stu[i].score[j] == perfect[j])
				stu[i].perfect++;
		}
	}
	qsort(stu + 1, n, sizeof(stu[0]), cmp);
	stu[1].rank = 1;
	for (i = 2; i <= n; i++)
		if (stu[i].total == stu[i - 1].total)
			stu[i].rank = stu[i - 1].rank;
		else
			stu[i].rank = i;
	for (i = 1; i <= n; i++) {
		if (stu[i].isshow == 1) {
			printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
			for (j = 1; j <= k; j++)
				if (stu[i].notcompiler[j] == 0)
					printf(" -");
				else
					printf(" %d", stu[i].score[j]);
			puts("");
		}
	}

	return 0;
}
