/*
 * 设计思路：
 * 和 [1039](https://blog.csdn.net/huaxuewan/article/details/101797582) 题类似。
 *
 * 思路 3（链表）：
 * * 学生信息用链表储存
 * * 输出需要排序时，将链表转化为数组
 * * 节点中未直接存字符串，排序过程中，不需要比较、交换字符串，（但似乎影响不大）
 *
 * 思路 2（取巧的方法）：
 * * 通过多次提交，可以确定所有课程中人数最多的为 398 人
 * * 直接用一个三维数组存储信息，排序后输出即可
 *
 * 思路 1（位运算超时）：
 * * 使用位运算储存每门课的学生信息
 * * 每门课下学生人数很少，即使用位记录学生信息同样造成很大的空间和时间的浪费
 */

//思路 3（链表）：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);
int toid(char s[]);

#define IDMAX (26 * 26 * 26 * 10)

struct course {
	int sum;
	struct stu *next;
};

struct stu {
	int name;
	struct stu *next;
};

struct course courses[2500] = {0};
char names[IDMAX][5] = {0};
int ans[40000] = {0};

int main(void)
{
	int n, k;
	char name[5] = {0};
	int c, id, num;
	struct stu *student = NULL;
	int i, j, v;
	
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s %d", name, &c);
		id = toid(name);
		strcpy(names[id], name);
		for (j = 0; j < c; j++) {
			scanf("%d", &num);
			num--;
			student = (struct stu*)malloc(sizeof(struct stu));
			student->name = id;
			student->next = courses[num].next;
			courses[num].next = student;
			courses[num].sum++;
		}
	}

	for (i = 0; i < k; i++) {
		printf("%d %d\n", i + 1, courses[i].sum);
		student = courses[i].next;
		j = 0;
		while (student) {
			ans[j] = student->name;
			student = student->next;
			j++;
		}
		qsort(ans, j, sizeof(ans[0]), cmp);
		for (v = 0; v < j; v++) {
			printf("%s\n", names[ans[v]]);
		}
	}
	return 0;
}

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int toid(char s[])
{
	int id = 0;
	int i;
	for (i = 0; i < 3; i++) {
		id = id * 26 + (s[i] - 'A');
	}
	id = id * 10 + (s[i] - '0');
	return id;
}

/*//思路 2（取巧的方法）：
#include <stdio.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return strcmp(a, b);
}

char names[2500][398][5] = {0};
int sum[2500] = {0};

int main(void)
{
	int n, k;
	char s[5] = {0};
	int c, num;
	int i, j;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s %d", s, &c);
		for (j = 0; j < c; j++) {
			scanf("%d", &num);
			num--;
			strcpy(names[num][sum[num]], s);
			sum[num]++;
		}
	}

	for (i = 0; i < k; i++) {
		printf("%d %d\n", i + 1, sum[i]);
		qsort(names[i], sum[i], sizeof(names[0][0]), cmp);
		for (j = 0; j < sum[i]; j++) {
			puts(names[i][j]);
		}
	}

	return 0;
}
*/

/*// 思路 1（位运算超时）：
#include <stdio.h>
#include <string.h>

#define IDMAX (26 * 26 * 26 * 10)

struct course {
	char c[IDMAX >> 3];
	int sum;
};

struct course courses[2500] = {0};
char names[IDMAX][5] = {0};

int main(void)
{
	int n, k;
	char name[5] = {0};
	int c, id, num;
	int i, j, v;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s %d", name, &c);
		id = toid(name);
		strcpy(names[id], name);
		for (j = 0; j < c; j++) {
			scanf("%d", &num);
			num--;
			courses[num].c[id >> 3] |= (128 >> (id & (8 - 1)));
			courses[num].sum++;
		}
	}

	for (i = 0; i < k; i++) {
		printf("%d %d\n", i + 1, courses[i].sum);
		for (j = 0; j < (IDMAX >> 3); j++) {
			for (v = 0; v < 8; v++) {
				if ((courses[i].c[j] & (128 >> v)) != 0) {
					printf("%s\n", names[j * 8 + v]);
				}
			}
		}
	}
	return 0;
}

int toid(char s[])
{
	int id = 0;
	int i;
	for (i = 0; i < 3; i++) {
		id = id * 26 + (s[i] - 'A');
	}
	id = id * 10 + (s[i] - '0');
	return id;
}
*/
