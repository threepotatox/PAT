/*
 * 设计思路：
 * 用循环遍历，满足题目条件即可输出
 */

#include <stdio.h>

int main()
{
	int m, x, y;
	int i, j, tmp, a, b;
	double c;

	scanf("%d %d %d", &m, &x, &y);

	for (i = 9; i > 0; i--) {
		for (j = 9; j >= 0; j--) {
			a = 10 * i + j;
			b = 10 * j + i;
			tmp = 9 * (i > j ? i - j : j - i);
			if (tmp * y == b * x) {
				c = b * 1.0 / y;
				printf("%d", a);
				printf(a > m ? " Cong" 
						: (a == m ? " Ping" : " Gai"));
				printf(b > m ? " Cong"
					       	: (b == m ? " Ping" : " Gai"));
				printf(c > m ? " Cong"
						: (c == m ? " Ping" : " Gai"));
				return 0;
			}
		}
	}

	printf("No Solution");
	return 0;
}
