/*
 * 设计思路：
 * 1. 输入过程中，记录每门成绩 1 - 100 分对应的人数
 * 2. 得分为 i 的排名，等于得分大于 i 的总人数加 1
 * 3. 每一次查询对应一次计算和输出
 *
 * 注：本程序中未存储每个学生对应的四个排名，若对同一学生重复查询需要重复计算（数据量较少，超时的可能性很小~~）
 */

#include <stdio.h>

struct student
{
	int id;
	int score[4];
};

int main(void)
{
	int n, m, id, scores[4][102] = {{0}};
	struct student students[2000];
	int i, j, k;

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		struct student *s = students + i;
		scanf("%d%d%d%d", &s->id, &s->score[1], &s->score[2], &s->score[3]);
		s->score[0] = (s->score[1] + s->score[2] + s->score[3]) / 3.0 + 0.5;
		for (j = 0; j < 4; j++)
			scores[j][s->score[j]]++;
	}

	for (i = 0; i < m; i++) {
		scanf("%d", &id);
		for (j = 0; j < n && students[j].id != id; j++)
			;
		
		if (j == n) {
			puts("N/A");
		} else {
			int ranks[4]= {0}, score, max = 3;

			for (k = 3; k >= 0; k--) {
			       for (score = 100; score >= students[j].score[k]; score--)
				       ranks[k] += scores[k][score + 1];
			       ranks[k]+= 1;
			       if (ranks[k] <= ranks[max])
				       max = k;
			}
			printf("%d %c\n", ranks[max], "ACME"[max]);
		}


	}
	return 0;
}
