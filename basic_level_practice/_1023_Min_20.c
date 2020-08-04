/*
设计思路：
保证 0 在输出第一个非 0 数字后输出
*/

#include <stdio.h>

int main()
{
    int n, zero;
    int i;
    scanf("%d", &zero);
    for(i = 1; i < 10; i++){
        scanf("%d", &n);
        while(n--){
            printf("%c", '0' + i);
            while(zero){/*若此处用 zero-- 判断第二层 while，第一层循环会使 zero 自减为负值，进入死循环*/
                printf("%c", '0');
                zero--;
            } 
        }
    }
    printf("\n");
    return 0;
}
