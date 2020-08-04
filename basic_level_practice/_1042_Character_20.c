/*
设计思路：
利用数组存储
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int keyboard[26] = {0}, max = 25;
    char ch;
    int i;
    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            keyboard[tolower(ch) - 'a']++;
        }
    }
    for(i = 25; i >= 0; i--){
        if(keyboard[i] >= keyboard[max]){
            max = i;
        }
    }
    printf("%c %d\n", max + 'a', keyboard[max]);
    return 0;
}
