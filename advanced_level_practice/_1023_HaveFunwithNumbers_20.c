/*
 * 设计思路：
 * * 利用标记数组记录每个数字出现的次数
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int count[10] = {0};
	char num[21] = {0};
	int flag, len, temp, i;

	scanf("%s", num);
	len = strlen(num);
	for (flag = 0, i = len - 1; i >= 0; i--) {
		temp = (num[i] - '0');
		count[temp]++;
		temp = temp * 2 + flag;
		if (temp >= 10) {
			temp = temp - 10;
			flag = 1;
		} else {
			flag = 0;
		}
		num[i] = (temp + '0');
		count[temp]--;
	}
	int flag2 = 0;
	for (i = 0; i < 10; i++)
		if (count[i] != 0)
			flag2 = 1;

	printf("%s", (flag == 1 || flag2 == 1) ? "No\n" : "Yes\n");
	if (flag == 1)
		printf("1");
	printf("%s", num);

	return 0;
}
