/*
 * 设计思路：
 * * 先更新 Msize 为第一个大于等于其本身的素数，表示真正的哈希表大小
 * * 平方探测法插入 N 个数据
 * * 查询 M 个数据的时间，就是指查找长度
 *
 * 注意：
 * * 查询时，j <= msize，正常来说 (a + 0 \* 0) % msize 等价于 (a + msize \* msize) % msize，所以不需要加等号
 * * 但本题需要有等于号，是因为不加 PAT 后台过不了
 */

#include <stdio.h>

int isprime(int n)
{
	int i;
	if (n <= 1)
		return 0;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main(void)
{
	int hash[10007] = {0};
	int msize, n, m;
	int i, j, a, pos;

	scanf("%d%d%d", &msize, &n, &m);
	while (!isprime(msize))
		msize++;
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		for (j = 0; j <= msize; j++) {
			pos = (a + j * j) % msize;
			if (hash[pos] == 0) {
				hash[pos] = a;
				break;
			}
		}
		if (j >= msize)
			printf("%d cannot be inserted.\n", a);
	}
	int sum = 0;
	for (i = 0; i < m; i++) {
		scanf("%d", &a);
		for (j = 0; j <= msize; j++) {
			sum++;
			pos = (a + j * j) % msize;
			if (hash[pos] == a || hash[pos] == 0)
				break;
		}
	}
	printf("%.1lf\n", sum * 1.0 / m);
	return 0;
}
