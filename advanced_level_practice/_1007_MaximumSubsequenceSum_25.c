/*
 * 设计思路：
 * 动态规划
 * * 函数 f(i) 表示以第 i 个数结尾的子数列的最大和，则：
 *      * 当 i = 0 或 f(i - 1) < 0 时，f(i) = data[i]；
 *      * 当 i != 0 且 f(i - 1) >= 0 时，f(i) = f(i - 1) + data[i]；
 * 注：输出头元素索引最小，则之前子列和为 0 的子列需要包含进来；输出尾元素索引最小，则之后子列和为 0 的子列不需要包含进来
 */

#include <stdio.h>

int main(void)
{
	int k;
       	int m, first;
	int tempstart, tempend, tempsum = -1;
	int start = -1, end, sum = 0;
	int i;

	scanf("%d", &k);
	for (i = 0; i < k;i++) {
		scanf("%d", &m);
		if (i == 0)
			first = m;

		if (tempsum < 0) {
			tempstart = m;
			tempsum = 0;
		}
		tempsum += m;
		if (tempsum >= 0)
			tempend = m;

		if (tempsum > sum || (!tempsum && !sum)) {
			start = tempstart;
			end = tempend;
			sum = tempsum;
		}
	}

	if (start == -1)
		printf("0 %d %d", first, m);
	else
		printf("%d %d %d", sum, start, end);

	return 0;
}
