/*
1013 数素数 （20 分）

令 Pi 表示第 i 个素数。现任给两个正整数 M≤N≤10^4，请输出 PM 到 PN 的所有素数。
输入格式：

输入在一行中给出 M 和 N，其间以空格分隔。
输出格式：

输出从 PM 到 PN 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
输入样例：

5 27

输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include <stdio.h>

int main()
{
    int m,n;
    int i,j,f,q;
    scanf("%d%d",&m,&n);
    
    i=2;f=1;q=0;
    while(f<=n){
        for(j=2;j*j<=i;j++)
            if(i%j==0) break;
        if(j*j>i){ 
            if(q%10>0)
                printf(" ");
            if(q>0&&q%10==0)
                printf("\n");
            
            if(f>=m){
                printf("%d",i);
                q++;    
            }
            f++;
        }
        i++;
    }
    printf("\n");
    return 0;
}
