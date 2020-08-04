/*
 * 设计思路：
 * * 利用数组存储二叉搜索树
 * * 因为是二叉搜索树，节点的值序列排序后即为此树的中序遍历
 * * 中序遍历的过程中将节点值依次插入节点
 * * 再层序遍历一遍输出
 */

#include <stdio.h>

struct node {
	int d;
	int left, right;
};

struct node tree[110];

int cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

void inorder(int root, int *d, int *i)
{
	if (root == -1)
		return ;
	inorder(tree[root].left, d, i);
	tree[root].d = d[*i];
	(*i)++;
	inorder(tree[root].right, d, i);
}

void levelorder()
{
	int q[110] = {0}, front = 0, rear = 1, cnt = 1;
	int root;
	while (cnt > 0) {
		root = q[front];
		printf("%s%d", front == 0 ? "" : " ", tree[root].d);
		front++;
		cnt--;
		if (tree[root].left != -1) {
			q[rear++] = tree[root].left;
			cnt++;
		}
		if (tree[root].right != -1) {
			q[rear++] = tree[root].right;
			cnt++;
		}
	}
}

int main(void)
{
	int n;
	int d[110], i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &tree[i].left, &tree[i].right);
	for (i = 0; i < n; i++)
		scanf("%d", &d[i]);
	qsort(d, n, sizeof(d[0]), cmp);
	int index = 0;
	inorder(0, d, &index);
	levelorder();
	return 0;
}
