/*
 * 设计思路：
 * 1. 输入的 Msize 若不是素数，需要重新赋值为第一个比它大的素数
 * 2. 平方探测法 index = (key + i * i) % size
 */

#include <stdio.h>

int isprime(int n)
{
	if (n == 1)
		return 0;
	int i;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int hash[10007], size;

void insert(int key)
{
	int index, i;
	for (i = 0; i < size; i++) {
		index = (key + i * i) % size;
		if (hash[index] == 0) {
			hash[index] = 1;
			printf("%d", index);
			return ;
		}
	}
	putchar('-');
}

int main(void)
{
	int n;
	int i, key;

	scanf("%d%d", &size, &n);
	while (!isprime(size))
		size++;
	for (i = 0; i < n; i++) {
		scanf("%d", &key);
		if (i != 0)
			printf(" ");
		insert(key);
	}
	return 0;
}
