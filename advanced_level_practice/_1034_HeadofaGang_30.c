/*
 * 设计思路：
 * DFS、连通分量
 * 1. 因为名字给的都是字母，所以在 C 中，还要考虑如何用数字保存和映射名字：
 * 三个字母组成的名字，直接按照 26 进制处理三位数，转换成数字，最大值为 17575；用 id 和 name 两个数组分别记录每个人的序号和名字，序号按照每个人的出现次序依次递增，最终还获得了输入的总人数 count，
 * 例如：`ABC` -> `28` -> `id[28] = count` -> `name[count] = ABC` -> `count++`
 *
 * 2. 用数组储存边和节点的权值，DFS 遍历图，记录下符合条件的团伙
 *
 * 3. 团伙输出前，依据头目名排序
 */

#include <stdio.h>
#include <string.h>

struct gang {
	int num;
	int member;
};

int toid(char s[]);
int dfs(int u, int *head, int *m, int *totalweight);
int cmp(const void *a, const void *b);

int g[2010][2010], w[2010], vis[2010];

int id[20000], count = 0;
char name[20000][4];

struct gang gangs[20000];
int sum = 0;

int n, k;

int main(void)
{
	char s1[4] = {0}, s2[4] = {0};
	int n1, n2, t;
	int i;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s %s %d", s1, s2, &t);
		n1 = toid(s1);
		n2 = toid(s2);
		g[n1][n2] += t;
		g[n2][n1] += t;
		w[n1] += t;
		w[n2] += t;
	}
	for (i = 1; i <= count; i++) {
		if (vis[i] == 0) {
			int head = i, m = 0, totalweight = 0;
			dfs(i, &head, &m, &totalweight);
			if (m > 2 && totalweight > k) {
				gangs[sum].num = head;
				gangs[sum].member = m;
				sum++;
			}
		}
	}

	qsort(gangs, sum, sizeof(gangs[0]), cmp);
	printf("%d\n", sum);
	for (i = 0; i < sum; i++)
		printf("%s %d\n", name[gangs[i].num], gangs[i].member);

	return 0;
}

int cmp(const void *a, const void *b)
{
	struct gang *s1 = (struct gang *)a, *s2 = (struct gang *)b;
	int n1 = s1->num, n2 = s2->num;
	return (strcmp(name[n1], name[n2]));
}

int dfs(int u, int *head, int *m, int *totalweight)
{
	int v;
	vis[u] = 1;
	(*m)++;
	if (w[u] > w[*head])
		*head = u;
	for (v = 1; v <= count; v++) {
		if (g[u][v] > 0) {
			(*totalweight) += g[u][v];
			g[u][v] = g[v][u] = 0;
			if (vis[v] == 0)
				dfs(v, head, m, totalweight);
		}
	}

	return 0;
}

int toid(char s[])
{
	int n = 0;
	int i = 0, temp = 0;

	if (s[i] != '\0') {
		n = (s[i] - 'A');
		i++;
		temp = 1;
	}
	while (s[i] != '\0') {
		temp *= 26;
		n += ((s[i] - 'A') * temp);
		i++;
	}
	if (id[n] == 0) {
		count++;
		id[n] = count;
		strcpy(name[count], s);
	}

	return id[n];
}
