/*
 * 题目大意：
 * 输入一组序列，输出该序列组成完全二叉搜索树后的层序遍历
 *
 * 设计思路：
 * * 序列排序后，即为二叉搜索树的中序遍历
 * * 又是完全二叉树，孩子节点的位置为父节点的 2 倍和 2 倍加 1
 * * 将这些性质结合，在中序遍历时，将中序序列赋值给层序序列
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int n, in[1010], level[1010], pos = 0;

void order(int root)
{
	if (root >= n)
		return;
	order(root * 2 + 1);
	level[root] = in[pos++];
	order(root * 2 + 2);
}

int main(void)
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &in[i]);
	qsort(in, n, sizeof(in[0]), cmp);
	order(0);

	printf("%d", level[0]);
	for (i = 1; i < n; i++)
		printf(" %d", level[i]);

	return 0;
}
