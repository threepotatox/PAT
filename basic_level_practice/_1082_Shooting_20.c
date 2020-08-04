/*
 * 设计思路：
 * 比赛规则简单，程序写起来也简单
 */

#include <stdio.h>

int main()
{
	int n, id, x, y;
	int min = 99999, max = -1, tmp;
	int best_id, worst_id;

	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d", &id, &x, &y);
		tmp = x * x + y * y;
		if (tmp < min) {
			min = tmp;
			best_id = id;
		}
		if (tmp > max) {
			max = tmp;
			worst_id = id;
		}
	}

	printf("%04d %04d", best_id, worst_id);

	return 0;
}
