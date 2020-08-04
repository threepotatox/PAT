/*
 * 设计思路：
 * 又是初看题目毫无头绪的题
 * 1.数组 v[101] 记录每个人说的话
 * 2.数组 a[101] 记录每次假设的实际身份，-1 为狼人，0 为好人
 * 3.每次假设后遍历一次每个人说的话，若和假设的身份冲突，说明此人说谎，添加至 lie[101]
 * 4.数组 lie[101] 最终有一个狼人和一个好人，则符合题目，否则，从第 2 步继续假设
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, v[101];
	int a[101], lie[101];
	int i, j, k, l, count;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", v + i);

	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			for (l = 1; l <= n; l++)
				a[l] = 1;
			a[i] = -1;
			a[j] = -1;
			count = 0;
			for (k = 1; k <= n; k++)
				if (v[k] * a[abs(v[k])] < 0)
					lie[count++] = k;
			if (count == 2 && a[lie[0]] + a[lie[1]] == 0) {
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution");
		
	return 0;
}
