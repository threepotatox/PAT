/*
 * 设计思路：
 * 使用队列实现广度优先遍历
 * * 每人仅转发一次，即不可重复入队
 * * 广度遍历时，判断最大层数不超过 L 层
 */

#include <stdio.h>

int v[1010][1010];
int n, l;
int bfs(int x)
{
	int sum = 0, level[1010] = {0}, visit[1010] = {0};
	int q[1010], front, rear;
	int i;

	q[0] = x;
	front = 0;
	rear = 1;
	visit[x] = 1;
	while (front != rear) {
		x = q[front];
		front++;
		for (i = 1; i <= n; i++) {
			if (v[x][i] && !visit[i] && level[x] < l) {
				sum++;
				visit[i] = 1;
				level[i] = level[x] + 1;
				q[rear] = i;
				rear++;
			}
		}
	}
	return sum;
}
int main(void)
{
	int i, j, k;

	scanf("%d%d", &n, &l);
	for (i = 1; i <= n; i++) {
	       scanf("%d", &j);
	       while (j--) {
		       scanf("%d", &k);
		       v[k][i] = 1;
	       }
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &j);
		printf("%d\n", bfs(j));
	}
	return 0;
}
