/*
 * 设计思路：
 * * 记录关系图和性别
 * * 循环遍历，记录符合条件的路径
 *
 * 注意：
 * * 不能直接按照整数读取，有 -0000 存在
 * * 若起始节点和终节点本身是好友，应判断此种情况，避免循环提前结束
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int v[10000][10000];
int c[10000], f[10000];

int cmp(const void *a, const void *b)
{
	int *arr1 = (int *)a, *arr2 = (int *)b;
	if (arr1[0] != arr2[0])
		return arr1[0] - arr2[0];
	return arr1[1] - arr2[1];
}

int main(void)
{
	int n, m;
	int ia, ib, ic, id, i, j, k;
	char a[10] = {'\0'}, b[10] = {'\0'};

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%s %s", a, b);
		if (a[0] != '-') {
			ia = atoi(a);
			f[ia] = 1;
		} else {
			ia = atoi(a + 1);
			f[ia] = 0;
		}
		if (b[0] != '-') {
			ib = atoi(b);
			f[ib] = 1;
		} else {
			ib = atoi(b + 1);
			f[ib] = 0;
		}
		v[ia][c[ia]++] = ib;
		v[ib][c[ib]++] = ia;
	}

	int result[30010][2], count;
	scanf("%d", &m);
	while (m--) {
		count = 0;
		scanf("%d %d", &ia, &ib);
		ia = (ia < 0 ? -ia : ia);
		ib = (ib < 0 ? -ib : ib);
		
		for (i = 0; i < c[ia]; i++) {
			if (v[ia][i] != ib && v[ia][i] != ia && f[v[ia][i]] == f[ia]) {
				ic = v[ia][i];
				for (j = 0; j < c[ic]; j++) {
					if (v[ic][j] != ib && v[ic][j] != ia && f[v[ic][j]] == f[ib]) {
						id = v[ic][j];
						for (k = 0; k < c[id]; k++) {
							if (v[id][k] == ib) {
								result[count][0] = ic;
								result[count][1] = id;
								count++;
							}
						}
					}
				}
			}
		}

		qsort(result, count, sizeof(result[0]), cmp);
		printf("%d\n", count);
		for (i = 0; i < count; i++)
			printf("%04d %04d\n", result[i][0], result[i][1]);
	}

	return 0;
}
