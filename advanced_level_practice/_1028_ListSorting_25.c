/*
 * 设计思路：
 * 按题目要求排序后，输出
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu {
	int id;
	char name[9];
	int grade;
};

int cmp1(const void *a, const void *b)
{
	struct stu *s1 = (struct stu*)a, *s2 = (struct stu*)b;
	return s1->id - s2->id;
}

int cmp2(const void *a, const void *b)
{
	struct stu *s1 = (struct stu*)a, *s2 = (struct stu*)b;
	int flag;
	flag = strcmp(s1->name, s2->name);
	if (flag)
		return flag;
	else
		return s1->id - s2->id;
}

int cmp3(const void *a, const void *b)
{
	struct stu *s1 = (struct stu*)a, *s2 = (struct stu*)b;
	int flag;
	flag = s1->grade - s2->grade;
	if (flag)
		return flag;
	else
		return s1->id - s2->id;
}

int main(v9id)
{
	int n, c;
	struct stu stus[100000] = {0};
	int i;

	scanf("%d %d", &n, &c);
	for (i = 0; i < n; i++)
		scanf("%d %s %d", &stus[i].id, stus[i].name, &stus[i].grade);

	if (c == 1)
		qsort(stus, n, sizeof(struct stu), cmp1);
	else if (c == 2)
		qsort(stus, n, sizeof(struct stu), cmp2);
	else
		qsort(stus, n, sizeof(struct stu), cmp3);

	for (i = 0; i < n; i++)
		printf("%06d %s %d\n", stus[i].id, stus[i].name, stus[i].grade);


	return 0;
}
