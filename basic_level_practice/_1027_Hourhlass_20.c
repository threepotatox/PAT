/*
设计思路：
  *
 ***
*****
如图仅观察一半图形，可设 n 为总行数，则第 m 行：
空格数 = n - m
符号数 = m * 2 -1
*/

#include <stdio.h>

int main()
{
    int n, m, i, j;
    char ch;

    scanf("%d %ch", &n, &ch);
    for(m = 1; 2*m*m-1 <= n; m++){
        continue;
    }
    m--;
    for(i = 0; i < 2*m-1; i++){
        for(j = 0; j < (i+1<=m ? i : m-(i+2-m)); j++){
            printf(" ");
        }
        for(j = 0; j < (i+1<=m ? (m-i)*2-1 : (i+2-m)*2-1); j++){
            printf("%c", ch);
        }
        printf("\n");
    }
    printf("%d\n", n - 2*m*m+1);

    return 0;
}
