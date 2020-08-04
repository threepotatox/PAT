/*
设计思路：
1.先约分，后输出
2.约分过程需要找最大公约数
*/

#include <stdio.h>

void printrational(long a, long b);
long MaxCommonDivisor(long a, long b);

int main()
{
    long a1, b1, a2, b2;
    char ch[4] = {'+', '-', '*', '/'};
    int i;

    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    for(i = 0; i < 4; i++){
        printrational(a1, b1);
        printf(" %c ", ch[i]);
        printrational(a2, b2);
        printf(" = ");
        switch(ch[i]){
            case '+': printrational(a1 * b2 + a2 * b1, b1 * b2); break;
            case '-': printrational(a1 * b2 - a2 * b1, b1 * b2); break;
            case '*': printrational(a1 * a2, b1 * b2); break;
            case '/': printrational(a1 * b2, b1 * a2); break;
        }
        printf("\n");
    }
    return 0;
}

void printrational(long a, long b)
{
    int sign = 1;
    long mcd = 1;
    if(b == 0){
        printf("Inf");
        return;
    }
    if(a < 0){
        a = -a;
        sign *= -1;
    }
    if(b < 0){
        b = -b;
        sign *= -1;
    } 
    mcd = MaxCommonDivisor(a, b);
    a /= mcd; b /= mcd;

    if(sign < 0) printf("(-");
    if(a / b && a % b){
        printf("%ld %ld/%ld", a / b, a % b, b);
    }
    else if(a % b){
        printf("%ld/%ld", a, b);
    }
    else{
        printf("%ld", a / b);
    }
    if(sign < 0) printf(")");
}

long MaxCommonDivisor(long a, long b)
{
    long x;
    while((x = a % b)){
        a = b;
        b = x;
    }
    return b;
}
