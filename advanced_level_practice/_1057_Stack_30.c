/*
 * 题目大意：
 * 实现一种栈，Push 栈顶入栈，Pop 栈顶出栈，PeekMedian 查询栈中所有元素的中值，
 *
 * 如果栈中有 N 个元素，若 N 为偶数，中值为第 (N / 2) 个最小值，若 N 为奇数，中值为第 ((N + 1） / 2) 个最小值
 *
 * 设计思路：
 * 关键词：树状数组，二分查找
 *
 * 1. 中值即为中位数，对元素排序，返回中间值即可，简单但会超时。
 *
 * 2. 如何让元素有序并能记录所在位置呢？可以用额外的数组，数组下标代表元素值，数组存储此元素出现的次数，查询中位数时累加各元素次数即可，但依旧耗时。
 *
 * 3. 利用树状数组，数组下标依旧代表元素值，但树状数组存储的可以看作是小于等于此元素值的元素出现的总次数，此时数组可以看作递增有序，然后利用二分快速查找符合条件的总次数
 *
 * * 最终思路利用树状数组和二分查找快速定位中位数
 *   * 树状数组 bit[]，
 *   * bit_sum(x) 获取小于等于当前元素 x 的出现总次数，
 *   * 二分查找快速定位 bit_sum(x) >= N / 2 的位置
 *
 * Reference：
 *   * 感谢[柳婼](https://blog.csdn.net/liuchuo/article/details/52231409)大神提供的思路
 *   * 学习什么是树状数组的链接
 *     * [Wikipedia 树状数组](https://zh.wikipedia.org/wiki/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84)
 *     * [OI Wiki 树状数组](https://oi-wiki.org/ds/fenwick/)
 */

#include <stdio.h>

#define MAX 100000

int stk[MAX], top = -1;
int bit[MAX];

int lowbit(int x)
{
	return x & (-x);
}

void bit_edit(int i, int delta)
{
	for (; i < MAX; i += lowbit(i))
		bit[i] += delta;
}

int bit_sum(int i)
{
	int sum = 0;
	for (; i > 0; i -= lowbit(i))
		sum += bit[i];
	return sum;
}

int peek_median()
{
	if (top == -1)
		return -1;
	int left = 0, right = MAX, k = top / 2 + 1;
	int sum, mid;

	while (left < right) {
		mid = (left + right) / 2;
		sum = bit_sum(mid);
		if (sum >= k)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int push(int x)
{
	if (top == MAX - 1)
		return -1;
	stk[++top] = x;
	bit_edit(x, 1);
	return x;
}

int pop()
{
	if (top == -1)
		return -1;
	bit_edit(stk[top], -1);
	return stk[top--];
}

int main(void)
{
	char op[11];
	int n, key;
	int i, ans;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", op);
		if (op[1] == 'u') {
			scanf("%d", &key);
			ans = push(key);
			if (ans == -1)
				printf("Invalid\n");
		} else if (op[1] == 'o') {
			ans = pop();
			if (ans == -1)
				printf("Invalid\n");
			else
				printf("%d\n", ans);
		} else {
			ans = peek_median();
			if (ans == -1)
				printf("Invalid\n");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}
