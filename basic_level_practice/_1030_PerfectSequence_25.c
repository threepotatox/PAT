/*
设计思路：
先快速排序原数列，从最小值遍历寻找最大的完美数列
题意 m 和 M 是对于完美数列的，这样 m 不同， M 也会变化，才有不同长度的完美数列
最初以为找到原始数列的最小值，并以此判断 M 来寻找完美数列（卒~）
*/

#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b);

int main()
{
    long long p, num[100000], min, max;
    int n, count = 0, i;
    scanf("%d %lld", &n, &p);
    for(i = 0; i < n; i++){
        scanf("%lld", &num[i]);
    }

    qsort(num, n, sizeof(long long), comp);

    for(min = 0, max = 0; max < n && count < n - min; min++){
        while(max < n && num[max] <= num[min] * p){
            max++;
        }
        if(count < max - min){
            count = max - min;
        }
    }
    printf("%d\n", count);

    return 0;
}

int comp(const void *a, const void *b)
{
    return *(long long *)a - *(long long *)b;
}
