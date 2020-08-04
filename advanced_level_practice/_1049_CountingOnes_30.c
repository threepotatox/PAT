/*
 * 设计思路：
 * 可以看作数学的排列组合问题，遍历计算每一位上 1 出现的次数并相加
 * * 遍历到每一位，分为三个部分，当前位的数值 now，左侧数值 left，右侧数值 right，now 在个位 i = 1，now 在十位 i = 10，now 在百位 i = 100……依次类推，则：
 *     * now == 0: count += (left * i);
 *     * now == 1: count += (left * i) + (right + 1);
 *     * now >= 2: count += (left * i) + (i);
 *
 * 例如：501255
 * * 遍历到百位时 now >= 2，则原数分为 `left=501` `2` `55=right`，将百位置为 1，
 *     * `left=[0, 500]` `1` `[0, 99]=right`，当 left=[0, 500] 任一值时，右侧可以 right=[0, 99] 中任一值
 *     * `left=501` `1` `[0, 99]=right`，当 left=501 时，右侧依旧可以 right=[0, 99] 中任一值而小于原数
 *     * 排列组合为 (501 X 100) + (100) = 50200
 * * 遍历到千位时 now == 1，则原数分为 `left=50` `1` `255=right`，将千位置为 1，
 *     * `left=[0, 49]` `1` `[0, 999]=right`，当 left=[0, 49] 任一值时，右侧可以 right=[0, 999] 中任一值
 *     * `left=50` `1` `[0, 255]=right`，当 left=50 时，右侧仅可以 right=[0, 255] 中任一值而小于原数
 *     * 排列组合为 (50 X 1000) + (255 + 1) = 50256
 * * 遍历到万位时 now == 0，则原数分为 `left=5` `0` `1255=right`，将万位置为 1，
 *     * `left=[0, 4]` `1` `[0, 9999]=right`当 left=[0, 4] 任一值时，右侧可以 right=[0, 9999] 中任一值
 *     * `left=5` `1` `null=right`，当 left=5 时，大于原数，右侧无法填入任何值
 *     * 排列组合为 (5 X 10000) + 0 = 50000
 * * 归纳总结即可得上方结论。同理，
 *     * 遍历到个位时，原数分为 `left=50125` `5` `null=right`，排列组合为 (50125 X 1) + (1) = 50126，
 *     * 遍历到十位时，原数分为 `left=5012` `5` `5=right`，排列组合为 (5012 X 10) + (10) = 50130，
 *     * 遍历到十万位，原数分为 `left=null` `5` `01255=right`，排列组合为 (0 X 100000) + (100000) = 100000，
 *     * 最终相加结果为 350712
 */

#include <stdio.h>

int main(void)
{
	int n;
	int count = 0, left = 0, now = 0, right = 0;
	int i;

	scanf("%d", &n);
	for (i = 1; n / i; i *= 10) {
		left = n / (i * 10);
		now = n / i % 10;
		right = n % i;
		if (now == 0) {
			count += (left * i);
		} else if (now == 1) {
			count += (left * i + right + 1);
		} else {
			count += (left * i + i);
		}
	}
	printf("%d", count);

	return 0;
}
