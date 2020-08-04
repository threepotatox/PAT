/*
设计思路：
加法实现：
每个 A 组成 PA 的个数，对应当前 P 的累加数
每个 T 组成 PAT 的个数，对应当前 PA 的累加数
PAT 总数为所有 T 对应 PAT 的累加
乘法实现：
一个 A，前面 P 的个数为 p，后面 T 的个数为 t，则组成 p * t 个 PAT
PAT 总数为所有 A 对应 p * t 的累加
*/

#include <stdio.h>

#define lim 1000000007

int main()
{
    int p = 0, pa = 0, pat = 0;
    char c;

    while((c = getchar()) != '\n'){
        if(c == 'P') p++;
        if(c == 'A') pa = (pa + p) % lim;
        if(c == 'T') pat = (pat + pa) % lim;
    }
    printf("%d", pat);
    return 0;
}
