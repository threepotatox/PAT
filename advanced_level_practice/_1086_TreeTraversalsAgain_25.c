/*
 * 设计思路：
 * * Push 的顺序即为先序遍历，Pop 的顺序即为中序遍历
 * * 根据先序和中序得到后序遍历
 */

#include <stdio.h>
#include <stdlib.h>

int pre[40], in[40], precnt = 0, incnt = 0;

void postorder(int iroot, int left, int right)
{
	if (left > right)
		return ;
	int i = left;
	while (in[i] != pre[iroot])
		i++;
	postorder(iroot + 1, left, i - 1);
	postorder(iroot + 1 + i - left, i + 1, right);
	printf("%d%s", pre[iroot], iroot == 0 ? "" : " ");
}

int main(void)
{
	int n;
	int s[40], top = -1;
	char str[10];
	int i, a;

	scanf("%d\n", &n);
	for (i = 0; i < 2 * n; i++) {
		gets(str);
		if (str[1] == 'u') {
			a = atoi(str + 5);
			pre[precnt++] = a;
			s[++top] = a;
		} else {
			in[incnt++] = s[top--];
		}
	}
	postorder(0, 0, n - 1);

	return 0;
}
