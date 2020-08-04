/*
设计思路：
利用数组直接统计，输出
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char ch;
    int m[10] = {0}, i;

    while(scanf("%c", &ch) && ch != '\n'){
        m[ch - '0']++;
    }
    for(i = 0; i < 10; i++){
        if(m[i]){
            printf("%d:%d\n", i, m[i]);
        }
    }

    return 0;
}
