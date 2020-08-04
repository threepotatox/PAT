/*
 * 设计思路：
 * * 边读取数据，边建立一颗二叉搜索树
 * * 建立完成后，再遍历一次，记录每层的个数，和最深层 max
 * * 输出最后两层的个数
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int d;
	struct node *left, *right;
};

struct node *build(struct node *root, int d)
{
	if (root == NULL) {
		root = (struct node *)malloc(sizeof(struct node));
		root->d = d;
		root->left = NULL;
		root->right = NULL;
	} else if (d <= root->d) {
		root->left = build(root->left, d);
	} else {
		root->right = build(root->right, d);
	}
	return root;
}

int level[1010] = {0}, maxdepth = 0;

void dfs(struct node *root, int depth)
{
	if (root == NULL) {
		maxdepth = maxdepth > depth ? maxdepth :depth;
		return ;
	}
	level[depth]++;
	dfs(root->left, depth + 1);
	dfs(root->right, depth + 1);
}

int main(void)
{
	int n, t;
	struct node *root = NULL;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		root = build(root, t);
	}
	dfs(root, 0);
	printf("%d + %d = %d", level[maxdepth - 1], level[maxdepth - 2], level[maxdepth - 1] + level[maxdepth - 2]);
	return 0;
}
