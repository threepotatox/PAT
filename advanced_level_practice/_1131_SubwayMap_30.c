/*
 * 设计思路：
 * 每次询问，DFS 计算一次
 * * v[][] 记录地铁图，line[][] 记录站点所在线路
 * * path[] 记录最终路径，transfer[] 记录最终路径的线路编号
 * * tpath[] 记录 dfs 过程中临时路径，ttransfer[] 记录 dfs 过程中临时路径的编号
 * * 根据经停站个数最少，换乘次数最小，记录最终值输出
 */

#include <stdio.h>

int v[10000][100], line[10000][1000];
int cnt[10000], visit[10000];
int start, end, min_count, min_transfer;
int path[10000], path_count, tpath[10000], tpath_count;
int transfer[10000], transfer_count, ttransfer[10000], ttransfer_count;

int transfer_sum(int *p, int c)
{
	int count = -1, i;
	for (i = 1; i < c; i++)
		if (p[i - 1] != p[i])
			count++;
	return count;
}

void dfs(int node, int count)
{
	if (node == end && ((count < min_count) || (count == min_count && transfer_sum(ttransfer, ttransfer_count) < min_transfer))) {
		min_count = count;
		min_transfer = transfer_sum(ttransfer, ttransfer_count);

		path_count = tpath_count;
		transfer_count = ttransfer_count;
		int i;
		for (i = 0; i < tpath_count; i++)
			path[i] = tpath[i];
		for (i = 0; i < ttransfer_count; i++)
			transfer[i] = ttransfer[i];
	}
	if (node == end)
		return ;
	int i;
	for (i = 0; i < cnt[node]; i++) {
		if (visit[v[node][i]] == 0) {
			visit[v[node][i]] = 1;
			tpath[tpath_count++] = v[node][i];
			ttransfer[ttransfer_count++] = line[node][i];
			
			dfs(v[node][i], count + 1);
			
			visit[v[node][i]] = 0;
			tpath_count--;
			ttransfer_count--;
		}
	}
}

int main(void)
{
	int n, m, k;
	int i, j, t, pre;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &m, &pre);
		for (j = 1; j < m; j++) {
			scanf("%d", &t);
			v[pre][cnt[pre]] = t;
			line[pre][cnt[pre]] = i;
			cnt[pre]++;
			
			v[t][cnt[t]] = pre;
			line[t][cnt[t]] = i;
			cnt[t]++;
			pre = t;
		}
	}
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d%d", &start, &end);
		min_count = 10000;
		min_transfer = 10000;
		ttransfer_count = 0;
		tpath_count = 0;
		
		ttransfer[ttransfer_count++] = 0;
		tpath[tpath_count++] = start;
		visit[start] = 1;

		dfs(start, 0);

		visit[start] = 0;
		tpath_count--;
		ttransfer_count--;

		int pretransfer = start;
		printf("%d\n", min_count);
		for (j = 2; j < transfer_count; j++) {
			if(transfer[j - 1] != transfer[j]) {
					printf("Take Line#%d from %04d to %04d.\n", transfer[j - 1], pretransfer, path[j - 1]);
				pretransfer = path[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", transfer[j - 1], pretransfer, end);
	}
	return 0;
}
