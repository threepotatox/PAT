/*
 * 设计思路：
 * * 结构体存储书的信息
 * * 每次查询命令对应一次查询
 *     * 查询函数中，因为结构体内成员的地址是相对地址，所以利用偏移量对应每次查询
 *
 * 注：若是把结构体中 keywords[] 改成一维数组，直接存储一行，keysearch 函数可以直接利用 strstr() 进行子串匹配，不仅能 AC，速度还很快（有匹配到更小子串的风险，但似乎并没有这样的测试点~）
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
	char id[8];
	char title[81];
	char author[81];
	char keywords[5][11];
	char publisher[81];
	char pubyear[5];
};

int cmp(const void *a, const void *b)
{
	return strcmp(((struct book*)a)->id, ((struct book*)b)->id);
}

void search(struct book books[], char s[], int n, int m)
{
	int f = 0, i = 0;
	for (; i < n; i++) {
		if (strcmp(books[i].id + m, s) == 0) {
			f = 1;
			printf("%s\n", books[i].id);
		}
	}
	if (f == 0)
		printf("Not Found\n");
}

void keysearch(struct book books[], char s[], int n)
{
        int f = 0, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 5; j++) {
			if (strcmp(books[i].keywords[j], s) == 0) {
				f = 1;
				printf("%s\n", books[i].id);
				break;
			}
		}
	}
	if (f == 0)
		printf("Not Found\n");
}

int main(void)
{
	int n, m;
	struct book books[10001] = {0};
	int i;
	scanf("%d", &n);getchar();
	for (i = 0; i < n; i++) {
		gets(books[i].id);
		gets(books[i].title);
		gets(books[i].author);
		int j = 0;
		char c = 0;
		while (scanf("%s%c", books[i].keywords[j], &c) && c != '\n')
			j++;
		gets(books[i].publisher);
		gets(books[i].pubyear);
	}
	qsort(books, n, sizeof(struct book), cmp);
	
	int move[6] = {0};
	struct book *p = NULL;
	for (i = 1; i < 6; i++)
		switch (i) {
			case 1: move[i] = (char*)(p->title) - (char*)p; break;
			case 2: move[i] = (char*)(p->author) - (char*)p; break;
			case 4: move[i] = (char*)(p->publisher) - (char*)p; break;
			case 5: move[i] = (char*)(p->pubyear) - (char*)p; break;
			default: break;
		}

	scanf("%d", &m);
	while (m--) {
		int num;
		char s[100] =  {0};
		scanf("%d: ", &num);
		gets(s);
		printf("%d: %s\n", num, s);
		if (num == 3)
			keysearch(books, s, n);
		else
			search(books, s, n, move[num]);
	}
	return 0;
}
