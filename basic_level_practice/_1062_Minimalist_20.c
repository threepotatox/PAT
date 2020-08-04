/*
 * 设计思路：
 * 利用最大公约数判断最简分数
 */

#include <stdio.h>

int gcd(int a, int b)
{
	if (b)
		while ((a %= b) && (b %= a)) ;
	return a + b;
}

int main()
{
	int n1, m1, n2, m2, k;
	int i, tmp;
	
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	if (n1 * m2 > n2 * m1){
		tmp = n1; n1 = n2; n2 = tmp;
		tmp = m1; m1 = m2; m2 = tmp;
	}

	tmp = 0;
	for (i = n1 * k / m1 + 1; m2 * i < n2 * k; i++)
		if (gcd(i, k) == 1)
			printf("%s%d/%d", tmp++ ? " " : "", i, k);

	return 0;
}
