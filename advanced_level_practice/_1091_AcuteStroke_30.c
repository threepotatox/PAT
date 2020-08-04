/*
 * 设计思路：
 * * 广度优先遍历，只不过扩展到三维，每个点有 6 个方向需要判断
 * * 6 个方向遍历的时候，要判断数组越界，是否连通，是否遍历过
 */

#include <stdio.h>

#define XMAX 1286
#define YMAX 128
#define ZMAX 60
#define DIRMAX 6

struct node {
	int x, y, z;
};

int xx[DIRMAX] = {1, -1, 0, 0, 0, 0};
int yy[DIRMAX] = {0, 0, 1, -1, 0, 0};
int zz[DIRMAX] = {0, 0, 0, 0, 1, -1};
int v[XMAX][YMAX][ZMAX];
int visit[XMAX][YMAX][ZMAX];
struct node q[XMAX * YMAX * ZMAX];
int front, rear;
int n, m, l, t;

int judge(int x, int y, int z)
{

	if (x < 0 || x >= m)
		return 0;
	if (y < 0 || y >= n)
		return 0;
	if (z < 0 || z >= l)
		return 0;
	if (v[x][y][z] == 0 || visit[x][y][z] == 1)
		return 0;
	return 1;
}

int bfs(int x, int y, int z)
{
	int sum = 0, i;
	struct node a, temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	visit[x][y][z] = 1;
	q[0] = temp;
	front = 0;
	rear = 1;
	while (front != rear) {
		a = q[front++];
		sum++;
		for (i = 0; i < DIRMAX; i++) {
			temp.x = a.x + xx[i];
			temp.y = a.y + yy[i];
			temp.z = a.z + zz[i];
			if (judge(temp.x, temp.y, temp.z)) {
				visit[temp.x][temp.y][temp.z] = 1;
				q[rear++] = temp;
			}
		}
	}
	return sum >= t ? sum : 0;
}

int main(void)
{
	int sum = 0;
	int i, j, k;
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for (i = 0; i < l; i++)
		for (j = 0; j < m; j++)
			for (k = 0; k < n; k++)
				scanf("%d", &v[j][k][i]);
	for (i = 0; i < l; i++)
		for (j = 0; j < m; j++)
			for (k = 0; k < n; k++)
				if (v[j][k][i] == 1 && visit[j][k][i] == 0)
					sum += bfs(j, k, i);
	printf("%d", sum);
	return 0;
}
