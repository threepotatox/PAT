/*
 * 设计思路：
 * [0-1 背包问题](https://www.jianshu.com/p/a66d5ce49df5)生动讲解
 * [递归+枚举的方法](https://blog.csdn.net/qq_39837806/article/details/104602530)
 * * 需要输出序列较小的答案，先对硬币排序从大到小，
 * * 然后按照 0-1 背包问题求解，即先选大面额的硬币，后续遇到小面额符合条件的就选择小面额
 * * 除了背包问题所需的 dp\[\] 递推数组，还需要额外建立 choice\[\]\[\] 数组表示硬币选择情况
 */

#include <stdio.h>

int cmp(const void *a, const void *b)
{
	return *((int *)b) - *((int *)a);
}

int main(void)
{
	int n, m;
	int dp[10010] = {0}, v[10010] = {0}, select[10010][110] = {0};
	int i, j;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	qsort(v + 1, n, sizeof(v[0]), cmp);
	for (i = 1; i <= n; i++) {
		for (j = m; j >= v[i]; j--) {
			if (dp[j] <= dp[j - v[i]] + v[i]) {
				select[i][j] = 1;
				dp[j] = dp[j - v[i]] + v[i];
			}
		}
	}
	if (dp[m] != m) {
		printf("No Solution");
	} else {
		int f = 0;
		i = n;
		j = m;
		while (j > 0) {
			if (select[i][j] == 1) {
				printf("%s%d", f ? " " : "", v[i]);
				f = 1;
				j -= v[i];
			}
			i--;
		}
	}
	return 0;
}
