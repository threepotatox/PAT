/*
 * 设计思路：
 * * 洗牌过程中，利用一个中间数组储存上一次结果
 * * 54 张牌每 13 张一组，在数组中存储数字，输出时利用除法和取余
 */

#include <stdio.h>

int main(void)
{
	int k;
	int sh[54], result[54], temp[54];
	int i, j;

	scanf("%d", &k);
	for (i = 0; i < 54; i++) {
		scanf("%d", &sh[i]);
		sh[i]--;
		result[i] = i;
	}
	for (i = 0; i < k; i++) {
		for (j = 0; j < 54; j++) {
			temp[j] = result[j];
		}
		for (j = 0; j < 54; j++) {
			result[sh[j]] = temp[j];
		}
	}

	char *p = "SHCDJ";
	printf("%c%d", p[result[0] / 13], result[0] % 13 + 1);
	for (i = 1; i < 54; i++) {
		printf(" %c%d", p[result[i] / 13], result[i] % 13 + 1);
	}
	return 0;
}
