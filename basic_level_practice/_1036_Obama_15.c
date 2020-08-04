/*
设计思路：
行数 == 1 || 行数 == (n - 1) / 2 || 列数 == 1 || 列数 == n，时输出符号
*/

#include <stdio.h>

int main()
{
    int n;
    char ch;
    int i, j;
    scanf("%d %c", &n, &ch);
    for(i = 0; i < (n + 1) / 2; i++){
        if(i == 0 || i == (n + 1) / 2 - 1){
            for(j = 0; j < n; j++){                
                printf("%c", ch);
            }
            printf("\n");
        }
        else{
            printf("%c", ch);
            for(j = 0; j < n - 2; j++){
                printf(" ");
            }
            printf("%c\n", ch);
        }
    }
    return 0;
}
