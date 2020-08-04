/*
 * 设计思路：
 * 思路 1：
 * * 遍历字符串：
 *     * 回文字串是奇数：以当前字符为中心，向两端延伸，判断回文子串长度；
 *     * 偶数：以当前字符和下一个字符为中心，判断回文字串长度；
 * * 时间复杂度：O(n^2)，最差情况下是 2 * n^2；
 *
 * 思路 2：动态规划
 * * 用二维数组 map[i][j] 记录子串 s[i]...s[j] 是否是回文子串，是记录 1，否记录 0，递推方法：
 *     * 初始化 map[i][i] = 1，map[i][i + 1] = 1；
 *     * 当 s[i] == s[j]，则 map[i][j] = map[i + 1][j - 1]；
 *     * 当 s[i] != s[j]，则 map[i][j] = 0；
 * * 每一次外层循环，判断了所有长度为 temp (temp 从 3 递增到 len) 的子串是否是回文串，最终得到回文子串的最大长度；
 * * 时间复杂度：O(n^2)，稳定于 n^2 / 2；
 * * 此方法来源自[柳婼](https://www.liuchuo.net/archives/2104)大神，感谢！
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int map[1001][1001] = {0};
	char s[1001] = {0};
	int max = 1, len, i, j;
	
	gets(s);
	len = strlen(s);
	for (i = 0; i < len; i++) {
		map[i][i] = 1;
		if (i < len - 1 && s[i] == s[i + 1]) {
			map[i][i + 1] = 1;
			max = 2;
		}
	}

	int temp;
	for (temp = 3; temp <= len; temp++) {
		for (i = 0; i + temp - 1 < len; i++) {
			j = i + temp - 1;
			if (s[i] == s[j] && map[i + 1][j - 1] == 1) {
				map[i][j] = 1;
				max = temp;
			}
		}
	}
	printf("%d", max);

	return 0;
}
