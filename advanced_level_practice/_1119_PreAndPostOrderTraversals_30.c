/*
 * 设计思路：
 * 重点在于理解先序和后序无法得到唯一中序的原因
 * * 先序遍历，中左右
 * * 后序遍历，左右中
 * * 每次遍历到根节点中时，需要确定左右子树，
 *   * 假设以先序的左找后序的左
 *   * 若后序的左和中之间有节点，说明中间节点即为右子树，所以能唯一确定左右子树
 *   * 若后序的左和中之间没有节点，那这个左节点既可以当左子树根，也可以当右子树根，出现了不唯一
 */

#include <stdio.h>

int n, pre[30], post[30];
int in[30], cnt = 0, flag = 1;

void inorder(int iroot, int left, int right)
{
	if (left >= right) {
		if (left == right)
			in[cnt++] = pre[iroot];
		return ;
	}
	int i = left;
	while (i < right && post[i] != pre[iroot + 1])
		i++;
	if (i == right - 1)
		flag = 0;
	inorder(iroot + 1, left, i);
	in[cnt++] = pre[iroot];
	inorder(iroot + 1+ i - left + 1, i + 1, right - 1);
}

int main(void)
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &post[i]);
	inorder(0, 0, n - 1);
	printf("%s\n", flag ? "Yes" : "No");
	for (i = 0; i < n; i++)
		printf("%s%d", i > 0 ? " " : "", in[i]);
	printf("\n");
	return 0;
}
