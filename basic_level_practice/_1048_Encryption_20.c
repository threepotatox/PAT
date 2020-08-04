/*
设计思路：
对奇数位和偶数位分别处理，位数不足以 0 对应
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char A[101], B[101];
    char encrypt[] = {"0123456789JQK"};
    int alen, blen, maxlen;
    int a, b, i;

    scanf("%s %s", A, B);
    alen = strlen(A), blen = strlen(B);
    maxlen = alen > blen ? alen : blen;

    for(i = 0; i < maxlen; i++){
        a = alen + i - maxlen < 0 ? 0 : A[alen + i - maxlen] - '0';
        b = blen + i - maxlen < 0 ? 0 : B[blen + i - maxlen] - '0';
        if((maxlen - i) % 2)
            putchar(encrypt[(a + b) % 13]);
        else
            putchar('0' + (b - a < 0 ? b - a + 10 : b - a));
    }

    return 0;
}
