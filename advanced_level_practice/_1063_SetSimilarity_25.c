/*
 * 题目大意：
 * 给多个集合，多次查询两个集合，输出每次查询的两个集合的相似度 `Nc / Nt * 100%`，Nc 为两集合中公共元素的个数，Nt 为两集合中不同元素的总个数，即 Nc 为两集合的交集，Nt 为并集
 *
 * 设计思路：
 * * 对每个集合排序去重，
 * * 经过排序，集合元素有序，查询两集合时，用两个指针从前往后遍历集合
 *   * 两指针元素相同，两指针同时向后走，Nc 和 Nt 均加 1
 *   * 指针元素不同，谁小谁向后走，仅 Nt 加 1
 *   * 最后将 Nt 加上未遍历完集合的剩余元素个数
 * * 输出查询结果
 */

#include <stdio.h>

int cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int sort_uniq(int arr[], int n)
{
	int i, j;
	qsort(arr, n, sizeof(arr[0]), cmp);

	for (i = 1, j = 0; i < n; i++) {
		if (arr[i] != arr[j]) {
			arr[++j] = arr[i];
		}
	}
	return j + 1;
}

int main(void) {
	int n, m, k;
	int sets[50][10001] = {0}, count[50] = {0};
	int i, j, temp;
	int a, b, nc, nt;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		for (j = 0; j < m; j++) {
			scanf("%d", &sets[i][j]);
		}
		count[i] = sort_uniq(sets[i], m);
	}

	scanf("%d", &k);
	for (m = 0; m < k; m++) {
		scanf("%d %d", &a, &b);
		a--;
		b--;
		nc = 0;
		nt = 0;
		for (i = 0, j = 0; i < count[a] && j < count[b];) {
			if (sets[a][i] == sets[b][j]) {
				nc++;
				nt++;
				i++;
				j++;
			} else {
				nt++;
				if (sets[a][i] < sets[b][j])
					i++;
				else
					j++;
			}
		}
		if (i < count[a])
			nt = nt + count[a] - i;
		else
			nt = nt + count[b] - j;
		printf("%.1f%%\n", (double)nc / nt * 100);
	}
	return 0;
}
