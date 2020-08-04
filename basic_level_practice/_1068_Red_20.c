/*
 * 设计思路：
 * 1.isunique() 判断唯一性，暴力查找（居然没超时）
 * 2.isdiff() 判断颜色差充分大，难点在于处理边界上的点
 * 3.用了变长数组，注意变长数组传递给函数要先传递大小
 */

#include <stdio.h>
#include <stdlib.h>

int isunique(int m, int n, int fig[n][m], int x, int y);
int isdiff(int m, int n, int fig[n][m], int x, int y, int tol);

int main()
{
	int m, n, tol;
	int i, j, count = 0, x, y;

	scanf("%d %d %d", &m, &n, &tol);

	int fig[n][m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &fig[i][j]);

	for (i = 0; count < 2 && i < n; i++) {
		for (j = 0; count < 2 && j < m; j++) {
			if (isunique(m, n, fig, j, i)
			&& isdiff(m, n, fig, j, i, tol)) {
				count++;
				y = i;
				x = j;
			}
		}
	}

	if (count == 0)
		printf("Not Exist");
	else if (count == 1)
		printf("(%d, %d): %d", x + 1, y + 1, fig[y][x]);
	else
		printf("Not Unique");

	return 0;
}

int isunique(int m, int n, int fig[n][m], int x, int y)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (fig[i][j] == fig[y][x] && !(i == y && j == x))
				return 0;
	return 1;
}

int isdiff(int m, int n, int fig[n][m], int x, int y, int tol)
{
	if((y > 0   && x > 0   ? abs(fig[y][x] - fig[y - 1][x - 1]) > tol : 1)
	&& (y > 0              ? abs(fig[y][x] - fig[y - 1][x    ]) > tol : 1)
	&& (y > 0   && x < m-1 ? abs(fig[y][x] - fig[y - 1][x + 1]) > tol : 1)
	&& (           x > 0   ? abs(fig[y][x] - fig[y    ][x - 1]) > tol : 1)
	&& (           x < m-1 ? abs(fig[y][x] - fig[y    ][x + 1]) > tol : 1)
	&& (y < n-1 && x > 0   ? abs(fig[y][x] - fig[y + 1][x - 1]) > tol : 1)
	&& (y < n-1            ? abs(fig[y][x] - fig[y + 1][x    ]) > tol : 1)
	&& (y < n-1 && x < m-1 ? abs(fig[y][x] - fig[y + 1][x + 1]) > tol : 1))
		return 1;
	return 0;
}
