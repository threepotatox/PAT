/*
 * 设计思路：
 * 转化为求顾客的入队时间，即可根据处理业务时间计算结束时间
 * * 结构体，每位顾客的入队时间 pushtime，处理业务时间 time
 * * 结构体，为每个窗口维护一个队列（入队过程中，此一维数组模拟循环队列，以防止数组越界，并节约空间），记录队首出队时间 poptime，队尾结束的时间 endtime
 * 1. 队列未满时，依次入队，入队过程中根据入队的顾客初始化队列
 *     * 初始化队列，此队列 `poptime = 第一位顾客的处理时间`，此队列结束时间 `endtime = 第一位顾客业务时间`
 *     * 继续入队列，此队列结束时间 `endtime += 顾客业务时间累加`
 * 2. 队列已满时，根据维护队列的 poptime，查询最先出队的顾客，此顾客出队列，黄线外下一顾客入队，出入队列过程更新此队列信息
 *     * 出队列，此队列 `poptime += 队列中第二位顾客的处理时间`
 *     * 入队列，此顾客的入队时间 `pushtime = 此队列的 endtime`，此队列结束时间 `endtime += 此顾客业务时间`
 * 3. 所有顾客入队完毕，其入队时间全部更新，即可查询
 *
 * 注：对 17:00 以前已经开始处理业务的顾客，不管处理到多晚，结束时间都如实输出，即 17:00 时银行不关门但不接受新业务;
 *
 *     1017 题不需要实际维护对应的队列，而本题需要，因为本题在队满出队时，必须要知道队列中第二位顾客的信息，才能更新此队列最新的出队时间，所以要维护完整的队列信息；
 */

#include <stdio.h>

struct window {
	int poptime;
	int endtime;
	int queue[11];
	int front, rear, length;
};

struct customer {
	int time;
	int pushtime;
};

int main(void)
{
	int n, m, k, q;
	struct window windows[21] = {0};
	struct customer customers[1001] = {0};
	int i, j;

	scanf("%d %d %d %d", &n, &m, &k, &q);
	int push = 0;
	for (i = 1; i <= k; i++) {
		scanf("%d",&customers[i].time);

		if (i <= m * n) {
			push = push % n;
			push++;
		} else {
			push = 1;
			for (j = 1; j <= n; j++) {
				if (windows[j].poptime < windows[push].poptime)
				push = j;
			}
		}

		if (windows[push].length == 0)
			windows[push].poptime = customers[i].time;
		if (windows[push].length == m) {
			windows[push].front++;windows[push].front %= 11;
			windows[push].length--;
			windows[push].poptime += customers[windows[push].queue[windows[push].front]].time;
		}
		customers[i].pushtime = windows[push].endtime;
		windows[push].endtime += customers[i].time;
		windows[push].queue[windows[push].rear] = i;
		windows[push].rear++;windows[push].rear %= 11;
		windows[push].length++;
	}
	for (i = 0; i < q; i++) {
		int tmp, query;
		scanf("%d", &query);
		tmp = customers[query].pushtime + customers[query].time;
		if (customers[query].pushtime >= (17 - 8) * 60)
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", tmp / 60 + 8, tmp % 60);
	}
	return 0;
}
