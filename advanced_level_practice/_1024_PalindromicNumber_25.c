/*
 * 设计思路：
 * * 数字倒序存储，把低位放在数组的低位，简化进位操作，需要在输入初始化时特殊处理一次
 * * 翻转数
 * * 大数相加
 * * 判断回文数
 *
 * 注：最终的字符串长度极限看着来？（跑~）
 */

#include <stdio.h>
#include <string.h>

int ispalindromic(char n[])
{
	int i, len = strlen(n);
	for (i = 0; i < len / 2; i++)
		if(n[i] != n[len -i - 1])
			return 0;
	return 1;
}

int reverse(char a[], char b[])
{
	int i, len = strlen(a);
	for (i = 0; i < len; i++)
		b[len - i - 1] = a[i];
	return 0;
}

int add(char a[], char b[])
{
	int i, flag = 0, sum = 0, len = strlen(a);
	for (i = 0; i < len; i++) {
		sum += (a[i] - '0') + (b[i] - '0');
		flag = sum / 10;
		sum %= 10;
		b[i] = (sum + '0');
		sum = flag;
	}
	if (sum)
		b[len] = (sum + '0');
	return 0;
}

int main(void)
{
	int k, steps;
	char num[101] = {0}, temp[101] = {0};

	scanf("%s %d", temp, &k);

	steps = 0;
	if (!ispalindromic(temp)) {
		reverse(temp, num);
		add(temp, num);
		for (steps = 1; steps < k && !ispalindromic(num); steps++) {
			reverse(num, temp);
			add(temp, num);
		}
	}
	
	reverse(num, temp);
	printf("%s\n%d", temp, steps);

	return 0;
}
