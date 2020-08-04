/*
 * 设计思路：
 * 读取输入，处理输出
 */

#include <stdio.h>

int main()
{
	int n, m, count;
	double g1, g2, g, gmax, gmin, gsum;
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%lf", &g2);
		gsum = 0;
		count = 0;
		gmin = m;
		gmax = 0;
		for (j = 0; j < n - 1; j++) {
			scanf("%lf", &g);
			if (g >= 0 && g <= m) {
				count++;
				gsum += g;
				if (g > gmax)
					gmax = g;
				if (g < gmin)
					gmin = g;
			}
		}
		g1 = (gsum - gmax - gmin) / (count - 2);
		printf("%d\n", (int)((g1 + g2 + 1) / 2));
	}
	return 0;
}
