/*
 * 设计思路：
 * 后序遍历的第一个节点一定是最左最下的那个节点
 * * 若左子树存在，则一定在左子树中
 * * 若左子树不存在，右子树存在，则一定在右子树，即一定在右子树的左子树中
 * * 若遍历到第一个叶节点，则为后序遍历的第一个节点
 */

#include <stdio.h>

int pre[50010], in[50010];

void find_post(int prel, int inl, int inr)
{
	if (inl == inr) {
		printf("%d", pre[prel]);
		return ;
	}
	int i = inl;
	while (in[i] != pre[prel])
		i++;

	if (i == inl)
		find_post(prel + 1, i + 1, inr);
	else
		find_post(prel + 1, inl, i - 1);
	return ;
}

int main(void)
{
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &in[i]);
	find_post(0, 0, n - 1);

	return 0;
}
