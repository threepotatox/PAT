/*
 * 设计思路：
 * 倍增法
 * 1. 利用先序和中序序列，dfs 遍历建立倍增法需要的信息
 * 2. 对于每次查询，用倍增法查询输出结果
 *
 * 理解倍增法，先看看倍增法的原始退化版，一倍倍增法：
 * * 对于每个节点用deep[] 记录节点深度，dp[] 数组记录自己的父节点
 * * 对于需要查询的两个节点，把深度大的节点利用 dp[] 记录的父节点，**一步一步跳**到深度小的节点的同一深度
 *   * 深度大的节点移动完后，若恰巧移动到了深度小的节点上，说明深度小的节点就是这两节点的祖先
 *   * 若不是，说明这两节点的祖先一定在深度更小的上方，因为此时俩节点深度相同，顺着 dp[] 俩节点同时**一步一步跳**，直到跳到同一节点，此节点即为俩节点的最低公共节点
 *
 * 节点很多，一步一步跳很容易超时，所以在此基础上，产生了真正的倍增法：
 * * dp[][] 的第二维记录每个节点跳 2<sup>j</sup> 层到达的父节点
 *     * dp[][0] 记录跳 1 = 2<sup>0</sup> 层的父节点
 *     * dp[][1] 记录跳 2 = 2<sup>1</sup> 层的父节点
 *     * dp[][2] 记录跳 4 = 2<sup>2</sup> 层的父节点
 *     * ……
 *     * dp[][31] 记录跳 2<sup>31</sup> 层的父节点，如果树的节点深度够深，有那么远的父节点有的话
 * * 与一倍跳法不同，倍增法，优**先大跳**，首先往最远跳，慢慢减小跳的距离，最终到达需要的节点，因为任意整数，一定等于若干 2<sup>j</sup> 相加
 * * 而且可以看出 INT 大小的树，极端情况退化成链表也只需跳 32 下就到根节点
 *
 * Reference：
 * * [最近公共祖先](https://oi-wiki.org/graph/lca/)
 * * [LCA问题（倍增法）](https://blog.csdn.net/q_m_x_d_d_/article/details/89924963)
 */

#include <stdio.h>

int pre[10010], in[10010];
int deep[10010], dp[10010][32];

int get_step(int x)
{
	int a, i;
	for (a = 1, i = 0; (a <<= 1) <= x; i++)
		;
	return i;
}

void lca(int iu, int iv)
{
	int temp, i;
	int flag = 1;
	int u = in[iu], v = in[iv];

	if (deep[iu] < deep[iv]) {
		temp = iu;
		iu = iv;
		iv = temp;
		flag = 0;
	}
	
	for (i = get_step(deep[iu] - deep[iv]); i >= 0; i--)
		if (deep[iu] - (1 << i) >= deep[iv])
			iu = dp[iu][i];
	if (iu == iv) {
		printf("%d is an ancestor of %d.\n", in[iu], flag ? u : v);
	} else {
		for (i = get_step(deep[iu]); i >= 0; i--) {// bu neng 32
			if (dp[iu][i] != dp[iv][i]) {
				iu = dp[iu][i];
				iv = dp[iv][i];
			}
		}
		printf("LCA of %d and %d is %d.\n", u, v, in[dp[iu][0]]);
	}

	return ;
}

void dfs(int iroot, int left, int right, int ifather, int d)
{
	if (left > right)
		return ;

	int i = left, j;
	while (i <= right && in[i] != pre[iroot])
		i++;
		
	deep[i] = deep[ifather] + 1;
	dp[i][0] = ifather;
	for (j = 1; (1 << j) <= deep[i]; j++)
		dp[i][j] = dp[dp[i][j - 1]][j - 1];
	dfs(iroot + 1, left, i - 1, i, d + 1);
	dfs(iroot + 1 + i - left, i + 1, right, i, d + 1);
}

int main(void)
{
	int n, m, u, v;
	int i, j;
	int iu, iv;
	
	scanf("%d%d", &m, &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &in[i]);
	for (i = 1; i <= n; i++)
		scanf("%d", &pre[i]);
	dfs(1, 1, n, 0, 1);

	for (i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		iu = 0;
		iv = 0;
		for (j = 1; j <= n; j++) {
			if (in[j] == u)
				iu = j;
			if (in[j] == v)
				iv = j;
		}
		if ((iu == 0) && (iv == 0)) {
			printf("ERROR: %d and %d are not found.\n", u, v);
		} else if (iu == 0) {
			printf("ERROR: %d is not found.\n", u);
		} else if (iv == 0) {
			printf("ERROR: %d is not found.\n", v);
		} else {
			lca(iu, iv);
		}
	}
	return 0;
}
