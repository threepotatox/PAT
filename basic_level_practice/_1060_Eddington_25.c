/*
设计思路：
初看题目有点绕，读懂题，重点在于求 E 天
1.降序排序骑车距离
2.天数由  0 升序，依次比较，即可找到最大天数
*/

#include <stdio.h>

int comp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    int n, e, miles[100000];
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", miles + i);
    qsort(miles, n, sizeof(int), comp);
    for(e = 0; e < n && miles[e] > e + 1; e++)
        continue;

    printf("%d\n", e);

    return 0;
}
