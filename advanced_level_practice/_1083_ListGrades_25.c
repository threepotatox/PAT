/*
 * 设计思路：
 * 直接排序，输出，学生成绩各不相同
 */

#include <stdio.h>

struct node {
	char name[11], id[11];
	int grade;
};

int cmp(const void *a, const void *b)
{
	return ((struct node *)b)->grade - ((struct node *)a)->grade;
}

int main(void)
{
	int n, g1, g2;
	struct node stu[100000];
	int cnt, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
	scanf("%d%d", &g1, &g2);
	qsort(stu, n, sizeof(stu[0]), cmp);
	int flag = 0;
	for (i = 0; i < n; i++) {
		if (stu[i].grade >= g1 && stu[i].grade <= g2) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("NONE");
	return 0;
}
