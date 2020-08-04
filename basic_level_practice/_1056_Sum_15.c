/*
设计思路：
可以直接用数学表达式计算：
sum1 = num1 x (n - 1) + num1 x (n - 1)  x 10
.
.
sum = (sum1 + sum2 + ……) = (num1 + num2 + ……) x (n - 1) x (10 + 1)
*/

#include <stdio.h>

int main()
{
    int n, num, sum = 0;
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        sum += num;
    }
    printf("%d\n", sum * (n - 1) * 11);
    return 0;
}
