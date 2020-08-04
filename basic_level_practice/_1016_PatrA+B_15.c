/*
设计思路：
使用 long 类型，防止数据溢出
*/

#include <stdio.h>

long partAB(long a, int da);

int main()
{
    long a, b;
    int da, db;
    scanf("%ld %d %ld %d", &a, &da, &b, &db);
    printf("%ld\n", partAB(a, da) + partAB(b, db));
    return 0;
}

long partAB(long a, int da)
{
    long pa = 0;
    while(a){
        if(a % 10 == da){
            pa = pa * 10 + da;
        }
        a /= 10;
    }
    return pa;
}
