/*
设计思路：
为四位数排序，然后输出
*/

#include <stdio.h>
#include <stdlib.h>

int sortnumber(int *n, int *m);
int compnumber(const void *a, const void *b);

int main()
{
    int n = 0, m = 0;
    scanf("%d", &n);
    do{
        sortnumber(&n, &m);
        printf("%04d - %04d = %04d\n", n, m, n - m);
        n = n - m;
    }while(n != 0 && n != 6174);
    return 0;
}

int sortnumber(int *n, int *m)
{
    int number[4] = {*n/1000, *n%1000/100, *n%100/10, *n%10};
    qsort(number, 4, sizeof(int), compnumber);
    *n = number[0]*1000 + number[1]*100 + number[2]*10 + number[3];
    *m = *n/1000 + *n%1000/100 *10 + *n%100/10 *100 + *n%10 *1000;
    return 0;
}

int compnumber(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
