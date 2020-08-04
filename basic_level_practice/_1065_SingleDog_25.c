/*
 * 设计思路：
 * 1.用 -1 当初始值，均为单身狗（因为有 0 号客人，所以最好不用 0 当初始值）
 * 2.用数组映射一对伴侣
 * 3.用 -2 表示客人到场。读取客人入场，用映射寻找自己的伴侣，当自己单身或伴侣还未到场，自己用 -2 表示到场
 * 4.若映射的伴侣状态为 -2 到场，则两人配对成功，两人用 -3 表示脱离单身狗标签，单身狗数目减二
 */

#include <stdio.h>

#define BLANK -1
#define ATTEND -2
#define PAIR -3

int main()
{
	int n, m, couple[100000];
	int id1, id2, count = 0;
	int i;
	for (i = 0; i < 100000; i++)
		couple[i] = BLANK;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &id1, &id2);
		couple[id1] = id2;
		couple[id2] = id1;
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &id1);
		if (couple[id1] >= 0 && couple[couple[id1]] == ATTEND) {
			couple[couple[id1]] = PAIR;
			couple[id1] = PAIR;
			count += 2;
		} else {
			couple[id1] = ATTEND;
		}
	}
        
	printf("%d\n", m - count);
	count = m - count;
	for (i = 0; i < 100000; i++)
		if (couple[i] == ATTEND)
			printf("%05d%s", i, --count? " " : "");
	
	return 0;
}

/*
此方案二（同样 AC）整体思路是，用正数记录伴侣，伴侣到场后更新映射值为相应的负数，这样最后彼此的映射值还在。但有 0 号客人，他正负都是 0，要对此特别处理，故采取了较好处理的方案一（用 -1、-2、-3 表示不同的状态）
#include <stdio.h>

int comp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n, m, couple[100001] = {0};
	int id1, id2, count = 0, id[100001];
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &id1, &id2);
		id1++;
		id2++;
		couple[id1] = id2;
		couple[id2] = id1;
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++){
		scanf("%d", &id[i]);
		id[i]++;
		id2 = abs(couple[id[i]]);
		couple[id2] *= -1;
	}

	qsort(id, m, sizeof(id[0]), comp);

	for (i = 0; i < m; i++)
		if (couple[id[i]] >= 0)
			count++;
	printf("%d\n", count);
	for (i = 0; i < m; i++)
		if (couple[id[i]] >= 0)
			printf("%05d%s", id[i] - 1, --count ? " " : "");

	return 0;
}
*/
