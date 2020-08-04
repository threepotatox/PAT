/*
设计思路：
利用空间大小为 100(对应百分制) 的数组存储相应分数的学生数
*/

#include <stdio.h>

int main()
{
    int n, grade[101] = {0}, x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        grade[x]++;
    }
    scanf("%d", &n);
    while(n){
        scanf("%d", &x);
        printf("%d%c", grade[x], n > 1 ? ' ' : '\n');
        n--;
    }
    return 0;
}
