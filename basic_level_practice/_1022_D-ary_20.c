/*
设计思路：
进制转换
*/

#include <stdio.h>

int main()
{
    int a, b, d, sum, x; 
    
    scanf("%d %d %d", &a, &b, &d);
    sum = a + b;
    
    for(x = 1; sum / d >= x; x *= d){
        continue;
    }

    for(;x > 0; sum %= x, x /= d){
        printf("%d", sum / x);
    }

    return 0;
}
