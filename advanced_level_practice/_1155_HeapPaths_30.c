/*
 * 设计思路：
 * * 按照由右到左 dfs 遍历完全二叉树，队列存储路径，遇到叶子节点输出路径
 * * 判断大小顶堆，父节点一直比子节点大为大顶堆，父节点一直比子节点小为小顶堆，否则不是堆
 */

#include <stdio.h>

int n, tree[1010];
int path[1010] = {0}, cnt = 0;

void dfs(int root)
{
	if (root > n)
		return ;
	path[cnt++] = tree[root];
	if (root * 2 > n) {
		int i;
		printf("%d", path[0]);
		for (i = 1; i < cnt; i++)
			printf(" %d", path[i]);
		printf("\n");
		cnt--;
		return ;
	}
	dfs(root * 2 + 1);
	dfs(root * 2);
	cnt--;
}

void is_heap()
{
	int min = 1, max = 1;
	int i;
	for (i = 2; i <= n; i++) {
		if (tree[i / 2] > tree[i])
			min = 0;
		else if (tree[i / 2] < tree[i])
			max = 0;
	}
	if (min == 1)
		printf("Min Heap");
	else if (max == 1)
		printf("Max Heap");
	else
		printf("Not Heap");
	return ;
}

int main(void)
{
	int i;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &tree[i]);
	dfs(1);
	is_heap();
	return 0;
}
