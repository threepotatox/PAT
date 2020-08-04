/*
 * 建立一个素数表，遍历素数表，查找质因子
 * * INT 最大值为 2147483647，开根号得 46340.95，素数表大小 5 万左右
 * * 所以不能被 5 万以内整除的数一定是素数
 * * 当最后 N > 1 时，state 是为了标示是否输出过因子，例如 30027 = 3 * 10009，最后输出 10009 前面要有 * 号
 */
#include<stdio.h>

#define MAX 46342
//INT 2147483647 46340.95
int main(void) {
	int prime[MAX] = {-1, -1};
	int i, j;
	for (i = 2; i * i < MAX; i++) {
		for (j = 2; i * j < MAX; j++) {
			prime[i * j] = -1;
		}
	}

	int n;
	scanf("%d", &n);
	printf("%d=", n);
	if (n == 1) {
		printf("1");
	}
	int state = 0;
	for (i = 2; i < MAX && n >= 2; i++) {
		int count = 0, flag = 0;
		while (prime[i] == 0 && n % i == 0) {
			count++;
			n /= i;
			flag = 1;
		}
		if (flag) {
			if (state) {
				printf("*");
			}
			printf("%d", i);
			state = 1;
		}
		if (count > 1) {
			printf("^%d", count);
		}
	}
	if (n > 1) {
		printf("%s%d", state ? "*": "", n);
	}

	return 0;
}
