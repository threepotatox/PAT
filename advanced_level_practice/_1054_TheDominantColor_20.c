/*设计思路：
 * 思路 2（计数）：
 * * 用 num 保存当前数字，count 表示数字出现的次数
 * * 当 下一个数字等于 num 时，count++，否则 count--
 * * 当 count == 0 时，num 重新保存当前数字
 * * 最终 num 保存的一定是出现次数最多的数字
 *
 * 思路 1（数组）：
 * * 用数组储存每个数字出现的次数，当次数大于一半时，输出此数字
 */

//思路 2（计数）：
#include <stdio.h>

int main(void)
{
	int m, n;
	int count = 0, num, temp;
	int i, j;
	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &temp);
			if (count == 0) {
				num = temp;
				count++;
			} else {
				if (temp == num) {
					count++;
				} else {
					count--;
				}
			}
		}
	}
	printf("%d", num);
	return 0;
}

/*//思路 1（数组）：
#include <stdio.h>

int hash[1 << 24] = {0};

int main(void)
{
	int m, n;
	int i, j, temp;
	scanf("%d %d", &m, &n);
	int half = m * n / 2;
	for (i = 0; i < n; i++) {
		for (j =  0; j < m; j++) {
			scanf("%d", &temp);
			hash[temp]++;
			if (hash[temp] > half) {
				printf("%d", temp);
				return 0;
			}
		}
	}
	return 0;
}
*/
