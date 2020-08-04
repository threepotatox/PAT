/*
 * 设计思路：
 * 输出中缀表达式，相当于中序遍历
 * * 左子树或右子树存在，需要 `()` 把左右子树括起来
 * * 把输出括号加入中序遍历
 */

#include <stdio.h>

struct node {
	char d[15];
	int left, right;
};

struct node tree[25];

int isleaf(int v)
{
	return tree[v].left == -1 && tree[v].right == -1;
}

void dfs(int v)
{
	if (tree[v].left != -1) {
		printf("%s", !isleaf(tree[v].left) ? "(" : "");
		dfs(tree[v].left);
		printf("%s", !isleaf(tree[v].left) ? ")" : "");
	}
	printf("%s", tree[v].d);
	if (tree[v].right != -1) {
		printf("%s", !isleaf(tree[v].right) ? "(" : "");
		dfs(tree[v].right);
		printf("%s", !isleaf(tree[v].right) ? ")" : "");
	}
}

int main(void)
{
	int n;
	int root, i, child[25] = {0};

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s %d %d", tree[i].d, &tree[i].left, &tree[i].right);
		if (tree[i].left != -1)
			child[tree[i].left] = 1;
		if (tree[i].right != -1)
			child[tree[i].right] = 1;
	}
	root = 1;
	while (child[root])
		root++;
	dfs(root);

	return 0;
}
