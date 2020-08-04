/*
 * 题目大意：
 * * 输入 np 只老鼠的体重，其序号从 0 递增，
 * * 第二行输入老鼠序号，即老鼠的出场顺序，每 ng 只老鼠为一组，每组中体重最大的老鼠晋级
 * * 按照老鼠的序号输出每只老鼠的排名
 * 思路设计：
 * 队列模拟晋级
 * * 队列存储老鼠出场的序号
 * * 每 ng 只老鼠中选择一只晋级，直到队列中剩余一只老鼠结束
 *     * 每一轮未晋级的老鼠排名等于，本轮次中晋级老鼠的数量加 1
 *     * 即等于本轮次中分组的数量加 1
 */

#include <stdio.h>

int main(void)
{
	int np, ng;
	int weights[1001] = {0}, ranks[1001] = {0}, queue[1001] = {0};
	int rank, max, count, index;
	int i;

	scanf("%d %d", &np, &ng);
	for (i = 0; i < np; i++) {
		scanf("%d", &weights[i]);
	}
	for (i = 0; i < np; i++) {
		scanf("%d", &queue[i]);
	}

	count = np;
	while (count > 1) {
		rank = (count % ng) ? (count / ng + 2): (count / ng + 1);
		index = 0;
		max = queue[0];
		for (i = 1; i < count; i++) {
			if (i % ng == 0) {
				queue[index] = max;
				index++;
				max = queue[i];
			} else {
				if (weights[queue[i]] > weights[max]) {
					ranks[max] = rank;
					max = queue[i];
				} else {
					ranks[queue[i]] = rank;
				}
			}
		}
		queue[index] = max;
		index++;
		count = index;
	}
	ranks[queue[0]] = 1;

	printf("%d", ranks[0]);
	for (i = 1; i < np; i++) {
		printf(" %d", ranks[i]);
	}

	return 0;
}
