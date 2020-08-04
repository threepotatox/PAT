/*
 * 思路 2（二分查找）：
 * * 数组 d[i] 存储第 1 个数到第 i 个数的和，则此数组一定递增
 * * 遍历左端点 i，在数组 d[i + 1, N] 范围内二分查找到第一个 d[j] >= d[i] + M 的右端点 j
 *     * 此二分查找是标准二分查找的变形，查找 [left, right] 范围内第一个大于或等于关键值的索引
 *     * 若没有符合条件的值，则 left 会遍历到 right + 1，
 *     * 记录结果前判断一次 j <= N
 * * 同样维护一个代价最小的期望值 max，记录结果
 */

#include <stdio.h>
#include <limits.h>

int search(int key, int d[], int left, int right)
{
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (d[mid] < key) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}

int main(void)
{
	int n, m, d[100002] = {0};
	int p[100000] = {0}, q[100000] = {0}, count = 0, max = INT_MAX;
	int sum = 0;
	int i, j;
	
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		d[i] += d[i - 1];
	}

	for (i = 0; i < n; i++) {
		j = search(d[i] + m, d, i + 1, n);
		if (j <= n) {
			sum = d[j] - d[i];
			if (sum < max) {
				max = sum;
				count = 0;
				p[count] = i + 1;
				q[count] = j;
				count++;
			} else if (sum == max) {
				p[count] = i + 1;
				q[count] = j;
				count++;
			}
		}
	}

	for (i = 0; i < count; i++) {
		printf("%d-%d\n", p[i], q[i]);
	}
	return 0;
}

/*
 * 设计思路：
 * * 维护一个窗口，窗口从头遍历到尾，并维护一个代价最小的期望值 max
 *     * if (sum < M)，窗口右侧右移
 *     * else if (sum >= M)，窗口左侧右移
 *         * if (sum < max)，即维护的代价最小的值需要改变，此时结果需要重新记录
 *         * if (sum == M)，符合当前代价最小的期望值，记录结果
 * * 原始序列右侧可以加一个值为 0 的哨兵，因为窗口到达序列尾部，依旧需要移动进行判断
 *     * 例如 M 的值为 9，序列为三个元素，加一个哨兵 0
 *     * 1, 3, 9, 0；到达尾部 9 后，左侧需要继续移动判断
 *     * 1, 3, 5, 0；到达尾部 5 后，右侧依旧可以进入循环体判断
 */
/*
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int n, m, d[100001] = {0};
	int p[100000] = {0}, q[100000] = {0}, count = 0, max = INT_MAX;
	int sum = 0;
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}

	i = 0; j = 0;
	while (i < n && j <= n) {
		if (sum < m) {
			sum += d[j];
			j++;
		} else {
			if (sum < max) {
				max = sum;
				count = 0;
				p[count] = i + 1;
				q[count] = j;
				count++;
			} else if (sum == max) {
				p[count] = i + 1;
				q[count] = j;
				count++;
			}
			sum -= d[i];
			i++;
		}
	}

	for (i = 0; i < count; i++) {
		printf("%d-%d\n", p[i], q[i]);
	}
	return 0;
}
*/
