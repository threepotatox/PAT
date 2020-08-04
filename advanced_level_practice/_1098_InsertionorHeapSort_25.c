/*
 * 设计思路：
 * 1. 插入排序的判断：
 * （开头一部分一定有序）&&（无序部分与原序列一致）
 *
 * 2. 堆排序的判断：
 * 排除法
 *
 * 3. 插入排序迭代一次：
 * 从断点迭代一次即可
 *
 * 4. 堆排序迭代一次，题目是大顶堆：
 *    1. 从后往前找第一个比堆顶元素小的元素，迭代一次堆排即可
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
	return 0;
}

int nextheap(int arr[], int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && arr[son] < arr[son + 1]) {
			son++;
		}
		if (arr[dad] > arr[son]) {
			return 0;
		} else {
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
	return 0;
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
		qsort(half, lenth + 1, sizeof(num[0]), cmp);
	} else {
		printf("Heap Sort\n");
		for (i = n -1; i > 1 && half[i] >= half[0]; i--) {
			;
		}
		swap(&half[i], &half[0]);
		nextheap(half, 0, i - 1);		
	}

	printf("%d", half[0]);
	for (i = 1; i < n; i++) {
		printf(" %d", half[i]);
	}

	return 0;
}
