/*
 * 设计思路：
 * 贪心算法：
 * * 注意车子最开始是没油的，若第一个加油站距离不为 0，即杭州没有加油站，汽车哪也去不了
 * * 手动添加一个在目的地的加油站，油价设为 0，在贪心策略下，汽车一定需要经过此站，以此判断是否能到达目的地，简化程序中的判断
 * 1. 在能够到达的最大距离内寻找加油站，如果找到一个比当前油价低的，那么下一站就是这个油价低的加油站，在当前加油站加油到刚好能到达下一站即可
 * 2. 在能够到达的最大距离内没有比当前价格更低的加油站，那就找尽可能低的加油站当做下一站，在当前加油站加满油前往；因为在本次最大距离内没有更便宜的站点了，油箱加满油，保证了本次最大距离内使用的是最便宜的油
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	double price;
	double dis;
};

int cmp(const void *a, const void *b)
{
	struct node *s1 = (struct node*)a, *s2 = (struct node*)b;
	return s1->dis > s2->dis ? 1 : -1;
}

int main(void)
{
	struct node sta[501];
	double cmax, d, davg;
	int n;
	int i;

	scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	for (i = 0; i < n; i++) {
		scanf("%lf%lf", &sta[i].price, &sta[i].dis);
	}
	sta[n].price = 0;
	sta[n].dis = d;
	qsort(sta, n + 1, sizeof(struct node), cmp);

	if (sta[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	} else {
		double maxdis = 0.0, nowtank = 0.0, totalprice = 0.0;
		int nowid = 0;
		while (sta[nowid].dis < d) {
			maxdis = sta[nowid].dis + cmax * davg;
			int nextid = -1, flag = 0;
			double minprice = sta[nowid + 1].price;
			for (i = nowid + 1; i <= n && sta[i].dis <=  maxdis && flag == 0; i++) {
				if (sta[i].price <= minprice) {
					minprice = sta[i].price;
					nextid = i;
					if (sta[i].price < sta[nowid].price) {
						flag = 1;
					}					
				}
			}
			if (nextid == -1) {
				printf("The maximum travel distance = %.2lf", maxdis);
				return 0;
			} else {
				double nexttank = (sta[nextid].dis - sta[nowid].dis) / davg;
				if (flag) {
					totalprice +=  (nexttank - nowtank) * sta[nowid].price;
					nowtank = 0.0;
				} else {
					totalprice += (cmax - nowtank) * sta[nowid].price;
					nowtank = cmax - nexttank;
				}
			}
			nowid = nextid;
		}
		printf("%.2lf", totalprice);
		return 0;
	}
}
