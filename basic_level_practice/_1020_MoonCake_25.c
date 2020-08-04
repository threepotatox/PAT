/*
设计思路：
利用循环找到单价最高的月饼出售，直到满足市场最大需求量
*/

#include <stdio.h>

int main()
{
    int n;
    float d, profit = 0, price[1000], stock[1000];
    int i, max;

    scanf("%d %f", &n, &d);
    for(i = 0; i < n; i++) scanf("%f", stock+i);
    for(i = 0; i < n; i++) scanf("%f", price+i);

    while(d > 0){
        max = 0;
        for(i = 0; i < n; i++){
            if(price[i] / stock[i] > price[max] / stock[max]){
                max = i;
            }
        }
        if(d > stock[max]){
            profit += price[max];
            d -= stock[max];
            price[max] = 0;
        }
        else{
            profit += d * price[max] / stock[max];
            d = 0;
        }
    }

    printf("%.2f\n", profit);

    return 0;
}
