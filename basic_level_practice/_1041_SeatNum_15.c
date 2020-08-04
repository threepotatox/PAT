/*
设计思路：
利用数组存储，检索
*/

#include <stdio.h>
#include <string.h>

typedef struct study{
    char num[17];
    int b;
}study;

int main()
{
    study studys[1001];
    int n, a, b;
    char num[17];
    scanf("%d", &n);
    while(n--){
        scanf("%s %d %d", num, &a, &b);
        strcpy(studys[a].num, num);
        studys[a].b = b;
    }
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        printf("%s %d\n", studys[a].num, studys[a].b);
    }
    return 0;
}
