/*
 * 设计思路：
 * 树的反转是指，每个节点的左右子树都做一次交换
 * * 输出遍历序列时，其实就是先访问右子树，再访问左子树
 * * 找到没有父节点的根节点，按照先右子树再左子树遍历输出
 */

#include <stdio.h>
#include <stdlib.h>

int tree[20][2];

void levelorder(int root)
{
	int q[20] = {root}, front = 0, rear = 1, cnt = 1;
	while (cnt > 0) {
		root = q[front];
		front++;
		cnt--;
		printf("%s%d", front > 1 ? " " : "", root);
		if (tree[root][0] != -1) {
			q[rear] = tree[root][0];
			rear++;
			cnt++;
		}
		if (tree[root][1] != -1) {
			q[rear] = tree[root][1];
			rear++;
			cnt++;
		}
	}
}

int flag = 0;
void inorder(int root)
{
	if (root == -1)
		return ;
	inorder(tree[root][0]);
	printf("%s%d", flag > 0 ? " " : "", root);
	flag = 1;
	inorder(tree[root][1]);
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
			tree[i][1] = atoi(a);
			child[atoi(a)] = 1;
		} else {
			tree[i][1] = -1;
		}
		if (b[0] != '-') {
			tree[i][0] = atoi(b);
			child[atoi(b)] = 1;
		} else {
			tree[i][0] = -1;
		}
	}

	while (child[root] == 1)
		root++;
	levelorder(root);
	puts("");
	inorder(root);
	return 0;
}
