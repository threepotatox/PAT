/*
 * 设计思路：
 * 用结构体存储男生和女生对应的信息，输出
 */

#include <stdio.h>

struct node {
	int grade;
	char name[11];
	char id[11];
};

int main(void)
{
	struct node t = {0}, m = {101}, f = {-1};
	int n;
	char sex;

	scanf("%d", &n);
	while (n > 0) {
		scanf("%s %c %s %d", t.name, &sex, t.id, &t.grade);
		if (sex == 'M') {
			if (t.grade < m.grade)
				m = t;
		} else {
			if (t.grade > f.grade)
				f = t;
		}
		n--;
	}

	if (f.grade > -1)
		printf("%s %s\n", f.name, f.id);
	else
		printf("Absent\n");
	if (m.grade < 101)
		printf("%s %s\n", m.name, m.id);
	else
		printf("Absent\n");
	if (f.grade > -1 && m.grade < 101)
		printf("%d\n", f.grade - m.grade);
	else
		printf("NA\n");

	return 0;
}
