/*
设计思路：
整数除法是截断取整，故四舍五入通过原始值加 50 实现（加 50 是因为除数是 100）
*/

#include <stdio.h>

int main()
{
    int c1, c2, t;

    scanf("%d %d", &c1, &c2);
    t = (c2 - c1 + 50) / 100;
    printf("%02d:%02d:%02d\n", t/3600, t%3600/60, t%60);
    return 0;
}
