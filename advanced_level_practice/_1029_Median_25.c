/*
 * 设计思路：
 * 1. 两个序列都存下来，会超过题目要求的内存限制
 *
 * 2. 储存第一个序列，第二个序列不储存，在输入的过程中寻找中间数；序列分别有 n1 和 n2 个数，则中间数在 (n + m + 1) / 2 的位置
 *
 * 3. 序列后面加一个最大值 INT_MAX 当“哨兵”，可以简化处理过程
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
	int n1, num1[200001], n2, num2, median;
	int i;
	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
		scanf("%d", &num1[i]);
	num1[n1] = INT_MAX;

	int *p = num1, n;
	scanf("%d", &n2);
	n = (n1 + n2 + 1) / 2;
	if (n2 > 0) {
		scanf("%d", &num2);
		n2--;
	} else {
		num2 = INT_MAX;
	}

	for (i = 0; i < n; i++) {
		if (*p < num2 && p < num1 + n1) {
			median = *p;
			p++;
		} else {
			median = num2;
			if (n2 > 0)
				scanf("%d", &num2);
			else
				num2 = INT_MAX;
			n2--;
		}
	}

	if (n)
		printf("%d", median);

	return 0;
}
