/*
设计思路：
利用数组存储成绩，找最大值输出
*/

#include <stdio.h>

int main()
{
    int n, school, score, max = 0;
    int schools[100000] = {0}, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d", &school, &score);
        schools[school - 1] += score;
    }
    for(i = 0; i < n; i++){
        if(schools[i] > schools[max]){
            max = i;
        }
    }
    printf("%d %d\n", max + 1, schools[max]);
    return 0;
}
