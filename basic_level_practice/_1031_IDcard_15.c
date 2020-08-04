/*
设计思路：
直接根据权重计算校验码
*/

#include <stdio.h>

int main()
{
    int n;
    int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    char id[19];
    int i, j, sum, count = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", id);
        for(j = 0, sum = 0; j < 17 && id[j] >= '0' && id[j] <= '9'; j++){
            sum += (id[j] - '0') * w[j];
        }
        if(j == 17 && id[17] == m[sum % 11]){
            count++;
        }
        else{
            puts(id);
        }
    }
    if(count == n){
        puts("All passed");
    }
    return 0;
}
