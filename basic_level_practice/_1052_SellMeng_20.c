/*
设计思路：
稍复杂的地方在于如何读取数据
*/

#include <stdio.h>

int main()
{
    int n, m[5];
    char c, ch[3][10][5] = {'\0'};
    int i, j;

    for(i = 0; i < 3; i++)
        for(j = 0; (c = getchar()) != '\n'; )
            if(c == '[')
                scanf("%[^]]", ch[i][j++]);

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", m + j);
            m[j]--;
        }
        if(m[0] < 0 || m[0] > 9 || !(*ch[0][m[0]])
        || m[1] < 0 || m[1] > 9 || !(*ch[1][m[1]])
        || m[2] < 0 || m[2] > 9 || !(*ch[2][m[2]])
        || m[3] < 0 || m[3] > 9 || !(*ch[1][m[3]])
        || m[4] < 0 || m[4] > 9 || !(*ch[0][m[4]]))
            puts("Are you kidding me? @\\/@");
        else
            printf("%s(%s%s%s)%s\n", ch[0][m[0]], ch[1][m[1]],
                    ch[2][m[2]], ch[1][m[3]], ch[0][m[4]]);
    }

    return 0;
}
