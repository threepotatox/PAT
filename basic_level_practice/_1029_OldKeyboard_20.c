/*
设计思路：
版本二：利用字符串 2，寻找完好的键盘并标记，再利用字符串 1 和标记，输出损坏的键盘
版本一：利用字符串 1 和 字符串 2 双重遍历，寻找损坏的键盘，并直接输出
*/

#include <stdio.h>
/*版本二*/
int main()
{
    int keyboard[128] = {0};
    char str[81], ch;
    int i;
    scanf("%s%c", str, &ch);
    while((ch = getchar()) != '\n'){
        keyboard[toupper(ch)] = 1;
    }
    i = 0;
    while(str[i] != '\0'){
        ch = toupper(str[i]);
        if(keyboard[ch - '\0'] == 0){
            putchar(ch);
            keyboard[ch - '\0'] = -1;
        }
        i++;
    }
    return 0;
}
/*版本一
int main()
{
    int keyboard[128] = {0};
    char str[81], str2[81];
    int i, j;

    scanf("%s%s", str, str2);
    i = 0;
    while(str[i] != '\0'){
        j = 0;
        while(str2[j] != '\0'){
            if(str2[j] == str[i]) break;
            j++;
        }
        
        if(str2[j] == '\0' && keyboard[str[i] - '\0'] == 0){
            keyboard[str[i] - '\0'] = 1;
            if(str[i] >= 'a' && str[i] <= 'z'){
                printf("%c", str[i] - 32);
                keyboard[str[i] - 32 - '\0'] = 1;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                printf("%c", str[i]);
                keyboard[str[i] + 32 - '\0'] = 1;
            }
            else{
                printf("%c", str[i]);
            }
        }
        
        i++;
    }

    return 0;
}
*/
