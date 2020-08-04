/*
 * 设计思路：
 * * 先遍历一遍看看所给节点是否在二叉树中
 * * 最低公共节点表示，两节点一定分别在最低公共节点左子树和右子树中
 * * 因为是二叉搜索树，所以两节点是否在某节点的左右子树，可以用节点值的大小判断
 */

#include <stdio.h>

int main(void)
{
	int n, m, pre[10010];
	int u, v, i, j;
	int iu, iv;

	scanf("%d%d", &m, &n);
	for (i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		iu = n;
		iv = n;
		for (j = 0; j < n; j++) {
			if (pre[j] == u)
				iu = j;
			if (pre[j] == v)
				iv = j;
		}
		if (iu == n && iv == n) {
			printf("ERROR: %d and %d are not found.\n", u, v);
		} else if (iu == n) {
			printf("ERROR: %d is not found.\n", u);
		} else if (iv == n) {
			printf("ERROR: %d is not found.\n", v);
		} else {
			for (j = 0; j < n; j++)
				if ((pre[j] >= u && pre[j] <= v) || (pre[j] >= v && pre[j] <= u))
					break;
			if (pre[j] == u)
				printf("%d is an ancestor of %d.\n", u, v);
			else if (pre[j] == v)
				printf("%d is an ancestor of %d.\n", v, u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, pre[j]);
		}
	}
	return 0;
}
