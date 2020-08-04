/*
 * 设计思路：
 * 注意：有多张空闲桌子的时候，非 VIP 用户选桌子编号最小的；当有 VIP 空桌时，VIP 用户会优先在 VIP 桌中选编号最小的；
 *
 * 1.两个结构体分别表示每对球友信息和球桌信息，第一次按照到达时间排序，即生成球友的等待队列，服务完成后，再根据开始时间排序输出；
 *
 * 2.总结一下本程序中提供服务的逻辑层次：
 *   * while 等待队列非空
 *       * 若队首是服务过的用户
 *           * 队首直接出列，continue
 *       * 根据队首的到达时间，寻找一张编号最小的空闲桌子或结束最早的
 *       * if 找到的是 VIP 桌
 *           * 队列里有 VIP 用户，选 VIP 用户
 *       * else 非 VIP 桌
 *           * 队首是 VIP 用户，寻找一张编号最小的空闲 VIP 桌
 *       * 若被服务的用户是队首用户
 *           * 队首出列
 */

#include <stdio.h>
#include <stdlib.h>

struct player {
	int arrive, time, vip;
	int start;
};

struct table {
	int end, vip;
	int count;
};

int cmp1(const void *a, const void *b)
{
	struct player *s1 = (struct player*)a, *s2 = (struct player*)b;
	return s1->arrive - s2->arrive;
}

int cmp2(const void *a, const void *b)
{
	struct player *s1 = (struct player*)a, *s2 = (struct player*)b;
	if (s1->start != s2->start)
		return s1->start - s2->start;
	else
		return s2->vip - s1->vip;
}

int main(void)
{
	struct player players[10000] = {0};
	struct table tables[100] = {0};
	int n, k, m;
	int i;

	for (i = 0; i < 100; i++)
		tables[i].end = 8 * 60 * 60;
	scanf("%d", &n);
	i = 0;
	while (i < n) {
		int hh, mm, ss, p;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &players[i].vip);
		players[i].arrive = (hh * 60 + mm) * 60 + ss;
		if (players[i].arrive < 21 * 3600) {
			players[i].time = (p <= 120 ? p * 60 : 120 * 60);
			i++;
		} else {
			n--;
		}
	}
	scanf("%d%d", &k, &m);
	for (i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		tables[num - 1].vip = 1;
	}

	qsort(players, n, sizeof(struct player), cmp1);

	i = 0;
	while (i < n) {
		if (players[i].start != 0) {
			i++;
			continue;
		}

		int numtable = 0, minnumtable = 0;
		int numplayer = i;
		for (int j = 0; j < k; j++) {
			if (tables[minnumtable].end > tables[j].end) {
				minnumtable = j;
			}
			if (tables[j].end <= players[i].arrive) {
				numtable = j;
				break;
			}
		}
		if (tables[numtable].end > players[i].arrive) {
			numtable = minnumtable;
		}

		if (tables[numtable].vip == 1) {
			for (int j = i; j < n && players[j].arrive <= tables[numtable].end; j++) {
				if (players[j].vip == 1 && players[j].start == 0) {
					numplayer = j;
					break;
				}
			}
		} else {
			if (players[i].vip == 1) {
				for (int j = 0; j < k; j++) {
					if (tables[j].vip == 1 && (tables[j].end <= players[i].arrive)) {
						numtable = j;
						break;
					}
				}
			}
		}
		
		if (players[numplayer].arrive <= tables[numtable].end) {
			players[numplayer].start = tables[numtable].end;
			tables[numtable].end += players[numplayer].time;
		} else {
			players[numplayer].start = players[numplayer].arrive;
			tables[numtable].end = players[numplayer].arrive + players[numplayer].time;
		}

		if (players[numplayer].start < 21 * 3600) {
			tables[numtable].count++;
		}

		if (numplayer == i)
			i++;
	}

	qsort(players, n, sizeof(struct player), cmp2);

	for (i = 0; i < n && players[i].start < 21 * 3600; i++) {
		printf("%02d:%02d:%02d ", players[i].arrive / 3600, players[i].arrive % 3600 / 60, players[i].arrive % 60);
		printf("%02d:%02d:%02d ", players[i].start / 3600, players[i].start % 3600 / 60, players[i].start % 60);
		printf("%d\n", (int)((players[i].start - players[i].arrive + 30) / 60));
	}
	if (k)
		printf("%d", tables[0].count);
	for (i = 1; i < k; i++)
		printf(" %d", tables[i].count);

	return 0;
}
