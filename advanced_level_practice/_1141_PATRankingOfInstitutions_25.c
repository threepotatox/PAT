#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	char id[7], school[7];
	int score;
};

struct school{
	char name[7];
	int score;
	int num;
};

int cmp_school(const void *a, const void *b)
{
	return strcmp(((struct student*)a)->school, ((struct student*)b)->school);
}

int cmp_score(const void *a, const void *b)
{
	struct school *s1 = (struct school*)a, *s2 = (struct school*)b;
	if (s1->score - s2->score)
		return s2->score - s1->score;
	else if (s1->num - s2->num)
		return s1->num - s2->num;
	else
		return strcmp(s1->name, s2->name);
}

int main()
{
	struct student stus[100001] = {0};
	struct school schs[100001] = {0};
	int n, m = 0, num = 0;
	double sum = 0;
	int i, j;
	char *tmp;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %d %s", stus[i].id, &stus[i].score, stus[i].school);
		for (tmp = stus[i].school; *tmp; tmp++)
			*tmp = tolower(*tmp);
	}
	
	qsort(stus, n, sizeof(stus[0]), cmp_school);
	
	for (i = 0; i < n; i++) {
		switch (stus[i].id[0]) {
			case 'B':
				sum += stus[i].score / 1.5;
				break;
			case 'A':
				sum += stus[i].score;
				break;
			case 'T':
				sum += stus[i].score * 1.5;
				break;
		}
		num++;
		if (i == n - 1 || strcmp(stus[i].school, stus[i + 1].school)) {
			strcpy(schs[m].name, stus[i].school);
			schs[m].score = (int)sum;
			schs[m].num = num;
			sum = 0;
			num = 0;
			m++;
		}
	}
	
	qsort(schs, m, sizeof(schs[0]), cmp_score);
	
	printf("%d\n", m);
	for (i = 0, j = 0; i < m; i++) {
		if (i > 0 && schs[i].score < schs[i - 1].score)
			j = i;
		printf("%d %s %d %d\n", j + 1, schs[i].name,
				schs[i].score, schs[i].num);
	}
	
	return 0;
}
