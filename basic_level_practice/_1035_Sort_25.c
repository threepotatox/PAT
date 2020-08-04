/*
设计思路：
1.插入排序的判断：
（开头一部分一定有序）&&（无序部分与原序列一致）

2.归并排序的判断：
排除法

3.插入排序迭代一次：
从断点迭代一次即可

4.归并排序迭代一次：
方法一：对原序列归并排序，匹配到题目第 2 个序列后，再迭代一次

方法二：关键在于确定归并段长度，然后列用归并段长度迭代一次第 2 个序列。
寻找归并段长度：
1.归并段最小长度为 1（表示序列未排序）
2.如图：（每个 L 范围内均有序）&&（每 2L 范围内均有序），则 L = 2L，否则终止。最终找到中间序列的归并段长度 L。
| L | L | L | L | L | L | L | L |
|   2L  |   2L  |   2L  |   2L  |
代码实现：tmp[N] 数组表示中间序列，且数组下标从 0 开始

int bool = 1;
for (L = 1, i = 1; i < N && bool; i *= 2) {
        for(j = i; j < N && bool; j += 2 * i){
                if(tmp[j - 1] > tmp[j]){
                        bool = 0;
                }
        }
        if(bool){
                L = 2 * i;
        }
}

感谢 Ionizing 大佬的博客，详细展示了各种错误姿势：
https://ionizing.science/2017/06/22/PAT%E9%A2%98%E8%A7%A3-B-1035/

最初想到像插入排序一样从头开始寻找最长有序子序列，来确定 L 值，此错误姿势破解如下，
10
2 1 8 3 7 5 9 4 0 6
1 2 3 8 5 7 4 9 0 6

我们无法从 1 2 3 8 是最长前置有序子列就判断出归并段的长度为 4，正确答案应该是 2

*/

#include <stdio.h>

int isinsertion(int n, int num[], int half[]);
int nextmerge(int n, int num[], int half[]);

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, num[100], half[100];
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &num[i]);
    for(i = 0; i < n; i++) scanf("%d", &half[i]);

    if(isinsertion(n, num, half)) nextmerge(n, num, half);

    for(i = 0; i < n; i++){
        printf("%d%c", num[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}

int isinsertion(int n, int num[], int half[])
{
    int i, lenth;
    for(i = 0; i < n - 1 && half[i] <= half[i + 1]; i++){
        continue;
    }
    for(i++, lenth = i; i < n && half[i] == num[i]; i++){
        continue;
    }
    if(i < n)
        return 1;
    printf("Insertion Sort\n");
    lenth++;
    qsort(num, lenth, sizeof(int), comp);
    return 0;
}

int nextmerge(int n, int num[], int half[])
{
    int i, j, lenth;
    printf("Merge Sort\n");
    for(lenth = 1, i = 0; i < n && lenth <= n; lenth *=2){
        for(i = 0; i < n && num[i] == half[i]; i++) ;
        for(j = 0; j < n / lenth; j++){
            qsort(num + j * lenth, lenth, sizeof(int), comp);
        }
        qsort(num + j * lenth, n % lenth, sizeof(int), comp);
    }
    return 0;
}
