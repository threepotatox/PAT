/*
 * 设计思路：
 * * 两楼层的相对位置，依次累加花费的时间
 */

#include <stdio.h>

int main(void)
{
	int n, time, cur, next;

	scanf("%d", &n);
	for (time = 0, cur = 0; n--; cur = next) {
		scanf("%d", &next);
		if (next > cur)
			time += (next - cur) * 6 + 5;
		else
			time += (cur - next) * 4 + 5;
	}

	printf("%d", time);

	return 0;
}
