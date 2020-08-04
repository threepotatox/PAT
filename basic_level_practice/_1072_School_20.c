/*
 * 设计思路：
 * 直接多重循环，依次判断，输出
 */

#include <stdio.h>

int main()
{
	int n, m, k, list[6], target;
	char name[5];
	int i, j, q, flag, stu_c = 0, item_c = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d", list + i);

	for (i = 0; i < n; i++) {
		flag = 0;
		scanf("%s %d", name, &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &target);
			for (q = 0; q < m; q++) {
				if(target == list[q]) {
					if (flag == 0) {
						flag = 1;
						stu_c++;
						printf("%s:", name);
					}
					item_c++;
					printf(" %04d", target);
				}
			}
		}
		if (flag)
			printf("\n");
	}
	printf("%d %d\n", stu_c, item_c);

	return 0;
}
