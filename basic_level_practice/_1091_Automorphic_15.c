/*
 * 设计思路：
 * 利用取余数进行比较
 */

#include <stdio.h>

int main()
{
	int m, k, n;
	int tmp, mask;

	scanf("%d", &m);
	while (m--) {
		scanf("%d", &k);
		for (n = 1; n < 10; n++) {
			tmp = n * k * k;

			for (mask = 1; mask <= k; mask *= 10)
				if (tmp / mask % 10 != k / mask % 10)
					break;
			if (mask > k) {
				printf("%d %d\n", n, tmp);
				break;
			}
		}
		if(n == 10)
			printf("No\n");
	}

	return 0;
}
