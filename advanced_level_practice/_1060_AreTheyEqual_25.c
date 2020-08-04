/*
 * 重点在于确定系数的有效数字和指数
 * * 去除小数点前的前导 0 后
 *   * 若小数点前有数字，指数为正
 *       * 则数字有几个，对应指数就为几
 *       * 保留有效位数
 *   * 若小数点前无数字，指数为负
 *       * 则小数点后有几个 0，对应指数就为负几
 *       * 保留有效位数
 * * 有效位数不足题目要求，后面补 0
 *
 * 这里提供一些测试用例，
 * 1 0 00.0 
 * 1 0.1 1.0
 * 2 0.0 0.0010
 * 4 00012.3 0.00123
 *
 * 注意：
 *    - 指数为 0 和 1 次方也要输出
 *    - 无需四舍五入
 */

#include <stdio.h>

int main(void) {
	int n;
	char num[2][110] = {0};
	char ch;
	int i, flag, flag2, count, exp[2] = {0};

	scanf("%d ", &n);
	for (i = 0; i < 2; i++) {
		flag = 0;
		flag2 = 0;
		count = 0;
		exp[i] = 0;
		while ((ch = getchar()) != ' ' && ch != '\n') {
			if (flag == 0) {
				if (ch == '.') {
					flag = -1;
					continue;
				} else if (ch > '0') {
					flag = 1;
				}
			}
			if (flag == -1) {
				if (ch != '0') {
					flag2 = 1;
				}
				if (flag2 == 0) {
					exp[i]--;
				} else if (flag2 == 1 && count < n) {
					num[i][count] = ch;
					count++;
				}
			}
			if (flag == 1) {
				if (ch != '.') {
					if (flag2 == 0) {
						exp[i]++;
					}
					if (count < n) {
						num[i][count] = ch;
						count++;
					}
				} else {
					flag2 = 1;
				}
			}
		}
		if (flag == -1 && flag2 == 0) {
			exp[i] = 0;
		}
		while (count < n) {
			num[i][count] = '0';
			count++;
		}
	}
	
	if (exp[0] == exp[1] && strcmp(num[0], num[1]) == 0) {
		printf("YES 0.%s*10^%d", num[0], exp[0]);
	} else {
		printf("NO 0.%s*10^%d 0.%s*10^%d", num[0], exp[0], num[1], exp[1]);
	}
	
	return 0;
}
