/*
设计思路：
总体设计方向是一层一层填充 m x n 的矩阵
1.确定 m 和 n 的值，n 从 sqrt(N) 趋于 0，第一个 N % n == 0 成立即找到
2.确定矩阵有几层，level = n / 2 + n % 2
3.每一层有四个方向
注意：如何保存矩阵？一种方法是直接利用一维数组模拟二维，但操作相对繁琐，本文采用变长数组进行保存，较为方便。不要预设矩阵为 10000 x 10000 大小后进行操作，提交后最后一个测试点会返回各种不同的结果，个人推测是因为计算过程中要对二维数组进行大量的寻址，造成大量时间空间的浪费，如下极端情况：N 为 9973 素数时矩阵形状
9973 0 ……
. 0 0 0 ……
. 0 0 0 ……
. 0 0 0 ……
3 0 0 0 ……
2 0 0 0 ……
1 0 0 0 ……
所有 0 的位置均无实际数据，但因二维数组在内存中是“一维”的，每次存取均要经过很多“0”才能到达正确地址
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}


int main()
{
    int N, m, n, num[10000];
    int i, j, k,level;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", num + i);

    qsort(num, N, sizeof(int), comp);
    for(n = sqrt((double)N); !(n > 0 && N % n == 0); n--)
        continue;
    m = N / n;
    
    int matrix[m][n];
    level = n / 2 + n % 2;
    for(i = 0, k = 0; i < level; i++){
        for(j = i; k <= N - 1 && j <= n - i - 1; j++)
            matrix[i][j] = num[k++];
        for(j = i + 1; k <= N - 1 && j <= m - i - 2; j++)
            matrix[j][n - i - 1] = num[k++];
        for(j = n - i - 1; k <= N - 1 && j >= i; j--)
            matrix[m - i -1][j] = num[k++];
        for(j = m - 2 - i; k <= N - 1 && j >= i + 1; j--)
            matrix[j][i] = num[k++];
    }

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            printf("%d%c", matrix[i][j], j != n -1 ? ' ' : '\n');
    
    return 0;
}
