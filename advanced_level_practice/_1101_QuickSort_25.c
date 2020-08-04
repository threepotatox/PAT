/*
设计思路：
主要是降低时间复杂度
1.以主元的定义，暴力判断，时间复杂度 O(N*N)
2.利用数组记录每个数前面的最大值，后面的最小值，时间复杂度 O(N)

最初解题时很简单的想到，在输入时记录每个数前面的最大值，然后就想怎么记录每个数后面的最小值，因为数据是从前往后读取，记录最小值的方法越想越乱，最后看到大佬的代码才反应过来，数据都存好了，从后往前再读一次就是最小值（囧，想撞死在键盘上~~）
*/

#include <stdio.h>

int main()
{
    int n, count = 0;
    int num[100000], lmax[100000], rmin[100000];
    int i, max, min;
    
    scanf("%d", &n);
    for(i = 0, max = i; i < n; i++){
        scanf("%d", num + i);
        lmax[i] = num[i] >= num[max] ? num[max = i] : num[max];
    }
    for(i = n - 1, min = i; i >= 0; i--){
        rmin[i] = num[i] <= num[min] ? num[min = i] : num[min];
    }

    for(i = 0; i < n; i++){
        if(num[i] == lmax[i] && num[i] == rmin[i]){
            count++;
        }
        else{
            num[i] = 0;
        }
    }
    printf("%d\n", count);
    for(i = 0; i < n && count; i++){
        if(num[i]){
            printf("%d%c", num[i], --count ? ' ' : '\0');
        }
    }
    printf("\n");

    return 0;
}
