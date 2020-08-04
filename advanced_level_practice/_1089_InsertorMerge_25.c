/*
 * 1. 插入排序的判断：
 * （开头一部分一定有序）&&（无序部分与原序列一致）
 *
 * 2. 归并排序的判断：
 * 排除法
 *
 * 3. 插入排序迭代一次：
 * 从断点迭代一次即可
 *
 * 4. 归并排序迭代一次：
 * * 方法一：对原序列归并排序，匹配到题目第 2 个序列后，再迭代一次
 * * 方法二：关键在于确定归并段长度，然后列用归并段长度迭代一次第 2 个序列。
 */

#include <stdio.h>

int cmp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int main(void)
{
	int n, num[100], half[100];
	int lenth, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d",&half[i]);
	}

	for (i = 0; i < n - 1 && half[i] <= half[i + 1]; i++) {
		;
	}
	for (i++, lenth = i; i < n && half[i] == num[i]; i++) {
		;
	}
	if (i >= n) {
		printf("Insertion Sort\n");
		if (lenth < n) {
			qsort(half, lenth + 1, sizeof(half[0]), cmp);
		}
	} else {
		printf("Merge Sort\n");
		
		int flag = 1;
		for (lenth = 1; lenth < n && flag; lenth *= 2) {
			for (i = lenth; i < n && flag; i += 2 * lenth) {
				if (half[i - 1] > half[i]) {
					flag = 0;
				}
			}
		}
		
		for (i = 0; i < n / lenth; i++) {
			qsort(half + i * lenth, lenth, sizeof(half[0]), cmp);
		}
		qsort(half + i * lenth, n % lenth, sizeof(half[0]), cmp);
	}

	printf("%d", half[0]);
	for (i = 1; i < n; i++) {
		printf(" %d", half[i]);
	}

	return 0;
}
