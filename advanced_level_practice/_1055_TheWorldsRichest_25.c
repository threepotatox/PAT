/*
 * 设计思路：
 * 排序
 * * 根据财富值递减、年龄递增、名字字典序将所有人排序
 * * 对于每次查询，遍历并将符合指定年龄区间的人输出
 */

#include <stdio.h>

struct node {
	char name[9];
	int age, worth;
};

int cmp (const void *a, const void *b)
{
	struct node *p1 = (struct node *)a, *p2 = (struct node *)b;
	if (p1->worth != p2->worth) {
		return p2->worth - p1->worth;
	} else if (p1->age != p2->age) {
		return p1->age - p2->age;
	} else {
		return strcmp(p1->name, p2->name);
	}
}

int main(void)
{
	struct node p[100000] = {0};
	int n, k;
	int m, min, max;
	int i, j, count;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	}
	qsort(p, n, sizeof(p[0]), cmp);
	for (i = 1; i <= k; i++) {
		count = 0;
		scanf("%d %d %d", &m, &min, &max);
		printf("Case #%d:\n", i);
		for (j = 0; count < m && j < n; j++) {
			if (min <= p[j].age && p[j].age <= max) {
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				count++;
			}
		}
		if (count == 0) {
			printf("None\n");
		}
	}

	return 0;
}
