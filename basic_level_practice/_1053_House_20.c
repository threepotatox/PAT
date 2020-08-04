/*
设计思路：
根据题目条件，计数输出即可
*/

#include <stdio.h>

int main()
{
    int n, d, k;
    double e, he;
    int empty = 0, pempty = 0, lower, i, j;

    scanf("%d %lf %d", &n, &e, &d);
    for(i = 0; i < n; i++){
        lower = 0;
        scanf("%d", &k);
        for(j = 0; j < k; j++){
            scanf("%lf", &he);
            if(he < e)
                lower++;
        }
        if(lower > k / 2 && k > d)
            empty++;
        else if(lower > k / 2)
            pempty++;
    }

    printf("%.1lf%% %.1lf%%", 100.0 * pempty / n, 100.0 * empty / n);

    return 0;
}
