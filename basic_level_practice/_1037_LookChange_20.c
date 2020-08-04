/*
设计思路：
换算成纳特(Knut)计算
*/

#include <stdio.h>

int main()
{
    int g, s, k, p, a, change;
    scanf("%d.%d.%d", &g, &s, &k);
    p = g * 29 * 17 + s * 29 + k;
    scanf("%d.%d.%d", &g, &s, &k);
    a = g * 29 * 17 + s * 29 + k;
    change = a - p;
    if(change < 0){
        change = -change;
        printf("-");
    }
    printf("%d.%d.%d\n", change / (29 * 17), change / 29 % 17, change % 29);
    return 0;
}
