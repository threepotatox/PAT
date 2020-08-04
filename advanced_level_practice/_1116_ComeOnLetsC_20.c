/*
设计思路：
用数组记录相应的获奖状态
*/

#include <stdio.h>

int isprime(int n)
{
    int i;
    for(i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int award[10000] = {0}, n, k, id;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &id);
        if(i == 0)
            award[id] = 1;
        else if(isprime(i + 1))
            award[id] = 2;
        else
            award[id] = 3;
    }
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        scanf("%d", &id);
        switch(award[id]){
            case 0: printf("%04d: Are you kidding?\n", id);             break;
            case 1: printf("%04d: Mystery Award\n", id); award[id] = 4; break;
            case 2: printf("%04d: Minion\n", id);        award[id] = 4; break;
            case 3: printf("%04d: Chocolate\n", id);     award[id] = 4; break;
            case 4: printf("%04d: Checked\n", id);                      break;
        }
    }

    return 0;
}
