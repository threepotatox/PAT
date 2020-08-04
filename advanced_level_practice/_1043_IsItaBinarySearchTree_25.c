/*
 * 设计思路：
 * 默认此搜索二叉树，左子树小于根结点，右子树大于等于根结点
 *
 * 1. 直接假设所给序列为搜索二叉树，递归子树建立后序遍历，建立过程中判断
 *     * 前序遍历的第一个值为根结点，左子树的值均小于根结点，右子树的值均大于等于根结点
 *     * 遍历过程中边界差值不为 1，则遍历失败
 * 2. 若不是，则假设序列为搜索二叉树的镜像，再次递归建立后序遍历
 * 3. 最后根据两次遍历结果输出
 */

#include <stdio.h>

int m = 0;
int post[1000] = {0};

void topost(int pre[], int root, int q)
{
	if (root > q) {
		return ;
	}

	int i = root + 1, j = q;
	while (i <= q && pre[root] > pre[i]) {
		i++;
	}
	while (j > root && pre[root] <= pre[j]) {
		j--;
	}

	if (i - j != 1) {
		return ;
	}
	topost(pre, root + 1, j);
	topost(pre, i, q);
	post[m] = pre[root];
	m++;
}

void topost2(int pre[], int root, int q)
{
	if (root > q) {
		return ;
	}
	
	int i = root + 1, j = q;
	while (i <= q && pre[root] <= pre[i]) {
		i++;
	}
	while (j > root && pre[root] > pre[j]) {
		j--;
	}

	if (i - j != 1) {
		return ;
	}
	topost2(pre, root + 1, j);
	topost2(pre, i, q);
	post[m] = pre[root];
	m++;
}

int main(void)
{
	int n, pre[1000];
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}

	topost(pre, 0, n - 1);
	if (m != n) {
		m = 0;
		topost2(pre, 0, n - 1);
	}
	if (m == n) {
		printf("YES\n%d", post[0]);
		for (i = 1; i < m; i++) {
			printf(" %d", post[i]);
		}
	} else {
		printf("NO");
	}
	return 0;
}
