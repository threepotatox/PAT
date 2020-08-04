/*
设计思路：
输入过程记录两人输赢次数，输出数据，注意如果解不唯一，则输出按字母序最小的解
*/

#include <stdio.h>

char max(int c, int j, int b);

int main()
{
    int n;
    char a, b;
    int awin = 0, awinc = 0, awinj = 0, awinb = 0;
    int bwin = 0, bwinc = 0, bwinj = 0, bwinb = 0;
    int flat = 0, i = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf(" %c %c", &a, &b);
        if(a == 'C' && b == 'J') awinc++;
        if(a == 'J' && b == 'B') awinj++;
        if(a == 'B' && b == 'C') awinb++;
        if(b == 'C' && a == 'J') bwinc++;
        if(b == 'J' && a == 'B') bwinj++;
        if(b == 'B' && a == 'C') bwinb++;
    }
    awin = awinc + awinj + awinb;
    bwin = bwinc + bwinj + bwinb;
    flat = n - awin - bwin;
    printf("%d %d %d\n", awin, flat, bwin);
    printf("%d %d %d\n", bwin, flat, awin);
    printf("%c %c\n",max(awinc, awinj, awinb),max(bwinc, bwinj, bwinb));

    return 0;
}

char max(int c, int j, int b){
    if(b >= c && b >= j) return 'B';
    if(c >  b && c >= j) return 'C';
    return 'J';
}
