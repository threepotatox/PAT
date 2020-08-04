/*
 * 设计思路：
 * 主要是注意录取规则：
 * * 学生总分 total = GE + GI，不除以 2 也没关系，总分越高，学生排名越高，若 total 相等且 GE 相等，两学生排名相同
 * * 按照学生排名由高到低，按照志愿尝试选择学校
 *   * 学校名额未满，学校录入学生
 *   * 学生排名和学校当前录取的最后一名学生排名相同，学校录入学生
 * * 输出每所学校的学生 ID
 *
 * 注意：
 *   * 学生排序时，仅需考虑总分和 GE，学校志愿不需要参与排序
 *   * 学生排序后，数组下标和学生 ID 不能依次对应了，所以要在结构体中记录学生的 ID，在最后输出，当时居然没发现，找了半天 bug，哭 (ㄒoㄒ)
 */

#include <stdio.h>
#include <stdlib.h>

struct app {
	int id, ge, gi, total, rank;
	int choice[5];
};

struct sch {
	int quota, cnt;
	int stu[40000];
};

struct app apps[40000] = {0};
struct sch schs[100] = {0};

int cmp(const void *a, const void *b)
{
	struct app *p = (struct app *)a, *q = (struct app *)b;
	if (p->total != q->total)
		return q->total - p->total;
	//if (p->ge != q->ge)
		return q->ge - p->ge;
	return p->choice[0] - q->choice[0];
}

int cmp2(const void *a, const void *b)
{
	return apps[*((int *)a)].id - apps[*((int *)b)].id;
}

int main(void)
{
	int n, m, k;
	int i, j;
	
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < m; i++)
		scanf("%d", &schs[i].quota);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &apps[i].ge, &apps[i].gi);
		apps[i].total = apps[i].ge + apps[i].gi;
		apps[i].id = i;
		for (j = 0; j < k; j++)
			scanf("%d", &apps[i].choice[j]);
	}

	qsort(apps, n, sizeof(apps[0]), cmp);
	int schid, laststu;
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			schid = apps[i].choice[j];
			laststu = schs[schid].stu[schs[schid].cnt - 1];
			if (schs[schid].cnt < schs[schid].quota
			|| (apps[i].total == apps[laststu].total && apps[i].ge == apps[laststu].ge)) {
				schs[schid].stu[schs[schid].cnt] = i;
				schs[schid].cnt++;
				break;
			}
		}
	}
	for (i = 0; i < m; i++) {
		qsort(schs[i].stu, schs[i].cnt, sizeof(schs[i].stu[0]), cmp2);
		for (j = 0; j < schs[i].cnt; j++)
			printf("%s%d", j == 0 ? "" : " ", apps[schs[i].stu[j]].id);
		puts("");
	}

	return 0;
}
