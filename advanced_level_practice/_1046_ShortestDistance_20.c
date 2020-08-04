/*
 * 设计思路：
 * * 用数组储存每个节点到第 1 个节点的总距离，dis[n] 的值等于整个环路的总距离，
 * * 所求结果等于两出口 dis[num2 - 1] - dis[num1 - 1] 和 dis[n] - (dis[num2 - 1] - dis[num1 - 1]) 之间的较小值
 */

#include <stdio.h>

int main(void)
{
	int n, m;
	int dis[100001] = {0};
	int i, temp, num1, num2, dis1, dis2;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		 scanf("%d", &temp);
		 dis[i] = dis[i - 1] + temp;
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &num1, &num2);
		if (num1 > num2) {
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
		dis1 = dis[num2 - 1] - dis[num1 - 1];
		dis2 = dis[n] - dis1;
		printf("%d\n", dis1 <= dis2 ? dis1 : dis2);
	}
	return 0;
}
