/*
 * 设计思路：
 * 难点在于确定 n<sub>1</sub>、n<sub>2</sub> 的值；
 *
 * 因为 U 分为 n<sub>1</sub>、n<sub>2</sub>、n<sub>3</sub> 三条边，且重叠了两个字符，所以设：
 * * n = 原字符串长度 + 2 = n<sub>1</sub> * 2 + n<sub>2</sub>；
 *     * 若 n % 3 == 0，则 n<sub>1</sub> == n<sub>2</sub> == n<sub>3</sub>；
 *     * 若 n % 3 > 0，并且需要 n<sub>2</sub> >= n<sub>1</sub>，那么把多出的余数给 n<sub>2</sub> 就行了；
 * * 所以 n<sub>1</sub> = n / 3，n<sub>2</sub> = n / 3 + n % 3；
 *
 * 确定了三条边的长度，利用一个头指针和一个尾指针，按行输出原字符串即可
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[81], *p, *q;
	int n1, n2, count;
	int i, j;

	scanf("%s", str);
	
	count = strlen(str) + 2;
	p = str;
	q = str + (count - 2 - 1);
	n1 = count / 3;
	n2 = count / 3 + count % 3;
	for (i = 0; i < n1 - 1; i++) {
		printf("%c", *p);
		p++;
		for (j = 1; j < n2 - 1; j++)
			printf(" ");
		printf("%c\n", *q);
		q--;
	}
	for (p; p <= q; p++)
		printf("%c", *p);

	return 0;
}
