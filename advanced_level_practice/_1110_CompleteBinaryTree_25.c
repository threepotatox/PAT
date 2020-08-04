/*
 * 设计思路：
 * 完全二叉树，最大的下标值一定等于最大的节点数
 * * 用数组存储二叉树
 * * 利用父节点的左右孩子 2 倍和 2 倍加 1，递归出最大的下标值
 */

#include <stdio.h>
#include <stdlib.h>

int tree[20][2];
int imax = 0, ilast = 0;
void dfs(int root, int index)
{
	if (imax < index) {
		imax = index;
		ilast = root;
	}
	if (tree[root][0] != -1)
		dfs(tree[root][0], index * 2);
	if (tree[root][1] != -1)
		dfs(tree[root][1], index * 2 + 1);
}
int main(void)
{
	int n;
	int i, root = 0, child[20] = {0};
	char a[3], b[3];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", a, b);
		if (a[0] != '-') {
			tree[i][0] = atoi(a);
			child[atoi(a)] = 1;
		} else {
			tree[i][0] = -1;
		}
		if (b[0] != '-') {
			tree[i][1] = atoi(b);
			child[atoi(b)] = 1;
		} else {
			tree[i][1] = -1;
		}
	}
	while (child[root] == 1)
		root++;
	dfs(root, 1);
	if (imax == n)
		printf("%s %d", "YES", ilast);
	else
		printf("%s %d", "NO", root);

	return 0;
}
