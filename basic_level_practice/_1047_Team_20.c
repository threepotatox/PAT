/*
设计思路：
利用数组，记录每支队伍的总分，找最大值输出
*/

#include <stdio.h>

int main()
{
    int n, team, member, score, teams[1000] = {0};
    int i, max = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d-%d %d", &team, &member, &score);
        teams[team - 1] += score;
    }
    for(i = 0; i < 1000; i++)
        if(teams[i] > teams[max])
            max = i;
    printf("%d %d\n", max + 1, teams[max]);

    return 0;
}
