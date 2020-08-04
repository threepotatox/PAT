/*
 * 设计思路：
 * * 利用数组记录每个编号询问的次数
 * * 推荐位未满最大值 K，直接进入推荐位，排序输出
 * * 推荐位已满最大值，仅需要和推荐位的末尾比较
 *
 * 注意：
 * * 每次询问过后，此编号的询问次数才能加 1
 * * 所以第一次询问时，推荐位为空，什么也不输出
 * * 题目中，K 最大为 10，所以排序最多只需要排 10 个数，最开始我直接全排序，然后直接超时
 */

#include <stdio.h>

struct node {
	int num;
	int cnt;
};

int cmp(const void *a, const void *b)
{
	struct node *p = (struct node *)a, *q = (struct node *)b;
	if (p->cnt != q->cnt)
		return q->cnt - p->cnt;
	return p->num - q->num;
}

int main(void)
{
	int n, k;
	int m[50010] = {0};
	struct node s[10] = {0};
	int num, f, i, j, count;//count 表示当前推荐位的总数

	scanf("%d%d", &n, &k);
	for (count = 0, i = 0; i < n; i++) {
		scanf("%d", &num);
		if (i != 0) {
			printf("%d:", num);
			qsort(s, count, sizeof(s[0]), cmp);
			for (j = 0; j < k && j < count; j++)
				printf(" %d", s[j].num);
			printf("\n");
		}
		m[num]++;
		for (f = 0; f < count && s[f].num != num; f++)
			;
 		if (f < count) {
			s[f].cnt = m[num];
		} else {
			if (f < k) {
				s[count].num = num;
				s[count].cnt = m[num];
				count++;
			} else if (s[k - 1].cnt < m[num] || (s[k - 1].cnt == m[num] && s[k - 1].num > num)) {
					s[k - 1].num = num;
					s[k - 1].cnt = m[num];
			}
		}	
	}
	return 0;
}
