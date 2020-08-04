/*设计思路：
 * BFS
 * 1. 邻接链表（数据较少，直接用了二维数组模拟）存取树
 * 2. 队列（一维数组模拟）实现 DFS，根节点入队
 * 3. 节点出队时，根据有无孩子进队
 *     * 无孩子节点进队，累加当前层的叶子节点数
 *     * 有孩子节点进队，根据出队父亲节点的层数，记录孩子节点的层数
 * 4. 输出每一层的叶子节点数
 *
 * 注：不能在建立树的过程中根据父亲节点记录孩子节点的层数，因为题目未保证输入节点的过程有序（毕竟 30 point(s)，否则太简单），所以不能保证当前的父亲节点已经记录了自己的层数，所以不能在建立树的过程中根据父亲节点记录其孩子节点的层数
 */

#include <stdio.h>

int main(void)
{
	int node[100][100] = {0}, depth[100] = {0};
	int n, m, id, cid, k;
	int i, j, count[100] = {0}, queue[100] = {0};

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &id, &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &cid);
			node[id][j] = cid;
			//depth[cid] = level[id] + 1;
		}
	}

	depth[1] = 1;
	queue[0] = 1;
	int *p = queue, *q = p + 1, maxdepth = -1;
	for (; p < q; p++) {
		for (k = 0; k < 100 && node[*p][k] != 0; k++) {
				*q = node[*p][k];
				depth[*q] = depth[*p] + 1;
				if (depth[*q] > maxdepth)
					maxdepth = depth[*q];
				q++;
		}
		if (k == 0)
			count[depth[*p]]++;
	}

	printf("%d", count[1]);
	for (i = 2; i <= maxdepth; i++)
		printf(" %d", count[i]);

	return 0;
}
