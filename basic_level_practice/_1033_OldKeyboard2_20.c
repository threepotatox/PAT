/*
设计思路：
1.利用 ASCII 记录键盘的损坏与否
2.无法输出有两种情况：
（键盘本身损坏）||（输出大写字母 && 上档键损坏）
*/

#include <stdio.h>

int main()
{
    int keyboard[128] = {0};
    char ch;
    while((ch = getchar()) != '\n'){
        keyboard[toupper(ch)] = -1;
    }
    while((ch = getchar()) != '\n'){
        if((keyboard[toupper(ch)]==-1) || (isupper(ch) && keyboard['+' - '\0']==-1)){
            continue;
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
