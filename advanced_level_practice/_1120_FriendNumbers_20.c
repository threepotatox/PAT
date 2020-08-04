/*
 * 设计思路：
 * 题目是朋友数，实际上求“朋友证号“，那就简单了（是的，简单了），最大数为 9999，最大的证号为 36，数组记录一下然后输出
 */

#include <stdio.h>

int main()
{
	int n, num;
	int friends[37] = {0};
	int i, sum = 0, count = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &num);
		for (sum = 0; num; num /= 10)
			sum += num % 10;
		if (!friends[sum]){
			friends[sum] = 1;
			count++;
		}
	}
	
	printf("%d\n", count);
	for (i = 1; i < 37; i++)
		if (friends[i])
			printf("%d%s", i, --count ? " " : "");

	return 0;
}
