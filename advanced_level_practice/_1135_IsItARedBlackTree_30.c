/*
 * 设计思路：
 * 1. 因为是二叉搜索树，且给了先序序列，所以可以直接建立一颗二叉搜索树
 * 2. 判断题目所给红黑树需满足的条件，仅需判断 2、4、5 条件
 *    1. 判断 2：根节点为黑
 *    2. 判断 4：节点为红，孩子节点为黑
 *    3. 判断 5：递归判断每个节点到叶子节点包含的黑节点个数
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data, red;
	struct node *left, *right;
};

struct node *build(struct node *root, int a)
{
	if (root == NULL) {
		root = (struct node *)malloc(sizeof(struct node));
		root->data = abs(a);
		root->red = a < 0 ? 1 : 0;
		root->left = NULL;
		root->right = NULL;
	} else if (abs(a) <= root->data) {
		root->left = build(root->left, a);
	} else {
		root->right = build(root->right, a);
	}
	return root;
}

int judge4(struct node *root)
{
	if (root == NULL)
		return 1;
	if (root->red) {
		if (root->left != NULL && root->left->red)
			return 0;
		if (root->right != NULL && root->right->red)
			return 0;
	}
	return judge4(root->left) && judge4(root->right);
}

int max(int a, int b)
{
	return a >= b ? a : b;
}

int get_sum(struct node *root)
{
	if (root == NULL)
		return 0;
	int l = get_sum(root->left);
	int r = get_sum(root->right);
	return root->red ? max(l, r) : max(l, r) + 1;
}

int judge5(struct node *root)
{
	if (root == NULL)
		return 1;
	int l = get_sum(root->left);
	int r = get_sum(root->right);
	if (l != r)
		return 0;
	return judge5(root->left) && judge5(root->right);
}

void free_tree(struct node *root)
{
	if  (root == NULL)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int main(void)
{
	int k, n;
	int i, a;

	scanf("%d", &k);
	while (k--) {
		struct node *root = NULL;//不能放在循环外
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a);
			root = build(root, a);
		}
		if (root->red || judge4(root) == 0 || judge5(root) == 0)
			printf("No\n");
		else
			printf("Yes\n");

		//free_tree(root);
		//未实现 free_tree(root);//释放内存
	}
	return 0;
}
