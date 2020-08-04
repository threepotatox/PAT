/*
设计思路：
直接在输入过程进行统计
*/

#include <stdio.h>

int main()
{
    int n, a1, a2, b1, b2;
    int a = 0, b = 0, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        if(a2 == a1 + b1 && b2 != a1 + b1)
            b++;
        if(a2 != a1 + b1 && b2 == a1 + b1)
            a++;
    }
    printf("%d %d\n", a, b);

    return 0;
}
