/*
 * 设计思路：
 * * 建树直接上 AVL 代码
 * * 层序遍历用队列遍历
 * * 判断完全二叉树
 *   * 若一个节点没有孩子节点，则这个节点后的所有节点也没有孩子节点，即为完全二叉树
 *   * 否则不是完全二叉树
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

	struct node *p[20], *temp;
	int front, rear, cnt;
	int child_null = 0, complete = 1;
	p[0] = root;
	front = 0;
	rear = 1;
	cnt = 1;
	while (cnt) {
		temp = p[front++];
		cnt--;
		printf("%s%d", temp == root ? "" : " ", temp->d);
		if (temp->left != NULL) {
			if (child_null)
				complete = 0;
			p[rear++] = temp->left;
			cnt++;
		} else {
			child_null = 1;
		}

		if (temp->right != NULL) {
			if (child_null)
				complete = 0;
			p[rear++] = temp->right;
			cnt++;
		} else {
			child_null = 1;
		}
	}
	printf("\n%s", complete ? "YES" : "NO");

	return 0;
}
