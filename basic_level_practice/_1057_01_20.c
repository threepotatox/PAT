/*
设计思路：
十进制和二进制的转化
*/

#include <stdio.h>

int main()
{
    char ch;
    int sum = 0, count[2] = {0};

    while((ch = getchar()) != '\n')
        if(isalpha(ch))
            sum += tolower(ch) - 'a' + 1;
    for(; sum; sum >>= 1)
        count[sum & 1]++;
    
    printf("%d %d\n", count[0], count[1]);

    return 0;
}
