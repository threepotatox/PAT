/*
 *直接上 AVL 代码，没有其他要求
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int d;
	struct node *left, *right;
};

int max(int a, int b)
{
	return a > b ? a : b;
}

int get_height(struct node *root)
{
	if (root == NULL)
		return 0;
	return max(get_height(root->left), get_height(root->right)) + 1;
}

struct node *left_rotate(struct node *root)
{
	struct node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

struct node *right_rotate(struct node *root)
{
	struct node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

struct node *right_left_rotate(struct node *root)
{
	root->right = right_rotate(root->right);
	return left_rotate(root);
}

struct node *left_right_rotate(struct node *root)
{
	root->left = left_rotate(root->left);
	return right_rotate(root);
}

struct node *insert(struct node *root, int d)
{
	if (root == NULL) {
		root = (struct node *)malloc(sizeof(struct node));
		root->d = d;
		root->left = NULL;
		root->right = NULL;
	} else if (d < root->d) {
		root->left = insert(root->left, d);
		if (get_height(root->left) - get_height(root->right) == 2)
				root = d < root->left->d ? right_rotate(root) : left_right_rotate(root);
	} else {
		root->right = insert(root->right, d);
		if (get_height(root->left) - get_height(root->right) == -2)
			root = d > root->right->d ? left_rotate(root) : right_left_rotate(root);
	}
	return root;
}

int main(void)
{
	int n;
	int i, t;
	struct node *root = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		root = insert(root, t);
	}
	printf("%d", root->d);
	return 0;
}
