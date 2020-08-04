/*
 * 设计思路：
 * 又是一道如何正确处理输入的题目
 */

#include <stdio.h>

int main()
{
	char c;
	int n, count, digit, alpha, notdot;

	scanf("%d", &n);
	while (getchar() != '\n')
		continue;

	while (n--) {
		count = 0; alpha = 0;
		digit = 0; notdot = 0;
		while ((c = getchar()) != '\n') {
			count++;
			if (isdigit(c))
				digit++;
			else if (isalpha(c))
				alpha++;
			else if (c != '.')
				notdot++;
		}
		if (count < 6)
			puts("Your password is tai duan le.");
		else if (notdot)
			puts("Your password is tai luan le.");
		else if (alpha && !digit)
			puts("Your password needs shu zi.");
		else if (digit && !alpha)
			puts("Your password needs zi mu.");
		else
			puts("Your password is wan mei.");
	}

	return 0;
}
