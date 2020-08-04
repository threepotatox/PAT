/*
设计思路：
注意精度范围，当值为负数且趋于 0 时，直接取整为零
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double r1, r2, p1, p2;
    double a, b;

    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    a = r1 * r2 * cos(p1 + p2);
    b = r1 * r2 * sin(p1 + p2);
    
    if(a < 0 && a > -0.005)
        a = 0;
    if(b < 0 && b > -0.005)
        b = 0;
    printf("%.2lf%+.2lfi\n", a, b);

    return 0;
}
