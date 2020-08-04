/*
设计思路：
利用数组存个数，不为 0 就继续输出
*/

#include <stdio.h>

int main()
{
    char ch, str[6] = {'P', 'A', 'T', 'e', 's', 't'};
    int keyboard[128] = {0}, f = 1, i;
    while((ch = getchar()) != '\n'){
        keyboard[(int)ch]++;
    }
    while(f){
        for(i = 0, f = 0; i < 6; i++){
            if(keyboard[(int)str[i]] > 0){
                putchar(str[i]);
                if(--keyboard[(int)str[i]]){
                    f = 1;
                }
            }
        }
    }
    return 0;
}
