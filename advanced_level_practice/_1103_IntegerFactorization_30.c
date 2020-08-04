/*
 * 设计思路：
 * * 建立不大于 N 的 i ^ K 数组，节约运算时间
 * * DFS 算法求解，dfs(index 当前 i 值，nowk 当前 k 个数，nowindexsum 当前所有 i 值的和，nowpowsum 当前所有 i ^ K 的和)
 *   * 因为序列可以有重复的值，所以有两个递归入口，dfs(index) 和 dfs(index - 1)
 *   * nowk 和 nowpowsum 判断终止递归
 *   * nowindexsum 判断字典序列大小
 *   * 因为需要字典序最大，所以 dfs 从最大值开始
 */

#include <stdio.h>
#include <math.h>

int n, k, p;
int pownum[410], cnt;
int result[410], rcnt, temp[410], tcnt;
int indexsum = 0;

void dfs(int index, int nowk, int nowindexsum, int nowpowsum)
{
	if (nowk >= k || nowpowsum >= n) {
		if (nowk == k && nowpowsum == n && nowindexsum > indexsum) {
			int i;
			for (i = 0; i < tcnt; i++)
				result[i] = temp[i];
			rcnt = tcnt;

			indexsum = nowindexsum;
		}
		return ;
	}
	if (index > 0) {
		temp[tcnt] = index;
		tcnt++;
		dfs(index, nowk + 1, nowindexsum + index, nowpowsum + pownum[index]);
		tcnt--;
		dfs(index - 1, nowk, nowindexsum, nowpowsum);
	}
}

void makepownum()
{
	int i, t;
	for (i = 1; i <= 400 && (t = pow(i, p)) <= n; i++)
		pownum[i] = t;
	cnt = i;
}

int main(void)
{
	scanf("%d%d%d", &n, &k, &p);
	makepownum();
	dfs(cnt - 1, 0, 0, 0);
	if (rcnt) {
		printf("%d = %d^%d", n, result[0], p);
		int i;
		for (i = 1; i < rcnt; i++)
			printf(" + %d^%d", result[i], p);
	} else {
		printf("Impossible");
	}
	return 0;
}
