/*
 * 设计思路：
 * 似乎又是一道排序题，处理好排序即可
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct score {
	char name[21];
	int program;
	int mid;
	int final;
	int total;
};

int cmp_sort_total(const void *a, const void *b)
{
	struct score *s1 = (struct score *)a;
	struct score *s2 = (struct score *)b;
	if (s2->total - s1->total)
		return s2->total - s1->total;
	return strcmp(s1->name, s2->name);
}

int cmp_sort_name(const void *a, const void *b)
{
	struct score *s1 = (struct score *)a;
	struct score *s2 = (struct score *)b;
	return strcmp(s1->name, s2->name);
}

int cmp_bsearch(const void *strptr, const void *scoreptr)
{
	struct score *s = (struct score *)scoreptr;
	char *name = (char *)strptr;
	return strcmp(name, s->name);
}

int main(void)
{
	struct score scores[10000], *s = scores;
	int p, m, n;
	int grade, sum = 0;
	int i;
	char name[21];
	
	scanf("%d %d %d", &p, &m, &n);
	
	for (i = 0; i < p; i++) {
		scanf("%s %d", name, &grade);
		if (grade >= 200) {
			strcpy(s->name, name);
			s->program = grade;
			s->mid = -1;
			s->final = -1;
			s->total = 0;
			sum++;
			s++;
		}
	}
	
	qsort(scores, sum, sizeof(scores[0]), cmp_sort_name);
	
	for (i = 0; i < m; i++) {
		scanf("%s %d", name, &grade);
		s = bsearch(name, scores, sum, sizeof(scores[0]), cmp_bsearch);
		if (s != NULL)
			((struct score *)s)->mid = grade;
	}
	for (i = 0; i < n; i++) {
		scanf("%s %d", name, &grade);
		s = bsearch(name, scores, sum, sizeof(scores[0]), cmp_bsearch);
		if (s != NULL) {
			s->final = grade;
			
			if (s->final >= s->mid)
				s->total = s->final;
			else
				s->total = s->final * 0.6 + s->mid * 0.4 + 0.5;
		}
	}
	
	qsort(scores, sum, sizeof(scores[0]), cmp_sort_total);
	
	for (s = scores, i = 0; i < sum && s->total >= 60; s++)
		printf("%s %d %d %d %d\n", s->name, s->program,
				s->mid, s->final, s->total);
	
	return 0;
}
