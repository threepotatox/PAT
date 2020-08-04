/*
设计思路：
多级比较，与 1015 题排序相类似，实现方法有所异同
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char name[6], maxname[6], minname[6], d[11], maxd[11] = {'9'}, mind[11]= {'0'};
    int n, x=0;
    scanf("%d", &n);
    while(n--){
        scanf("%s %s", name, d);
        if(strcmp(d, "1814/09/06") >= 0 && strcmp(d, "2014/09/06") <= 0){
            if(strcmp(d, maxd) <= 0){
               strcpy(maxname, name);
               strcpy(maxd, d);
            }
            if(strcmp(d, mind) >= 0){
                strcpy(minname, name);
                strcpy(mind, d);
            }
            x++;
        }
    }
    if(x)
        printf("%d %s %s\n", x, maxname, minname);
    else
        printf("0\n");
    return 0;
}
