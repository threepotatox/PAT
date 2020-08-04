/*
设计思路：
1.利用数组存储节点
2.利用初始地址及 next 地址，为列表排序，并以 -1 为终点，记录真实节点数目
3.根据 k 值，反转链表，利用数组下标，对称交换即可
（最初想用链表的 next 地址值尾插反转链表，突然想到，此地址值并不是真的内存地址,卒~）
*/

#include <stdio.h>

typedef struct link{
    int addr;
    int data;
    int next;
}link;

int inputlink(int n, link links[]);
int sortlink(int n, int a, link links[]);
int reverselink(int n, int k, link links[]);
int printlink(int n, link links[]);

int main()
{
    int a, n, k;
    link links[100000] = {0};

    scanf("%d %d %d", &a, &n, &k);
    inputlink(n, links);

    n = sortlink(n, a, links);
    reverselink(n, k, links);

    printlink(n, links);

    return 0;
}

int inputlink(int n, link links[])
{
    int i;
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &links[i].addr, &links[i].data, &links[i].next);
    }
    return 0;
}

int sortlink(int n, int a, link links[])
{
    int i, j;
    link temp;
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if(links[j].addr == (i ? links[i - 1].next : a)){
                temp = links[i];
                links[i] = links[j];
                links[j] = temp;
                break;
            }
        }
        if(links[i].next == -1)
            n = i + 1;
    }
    return n;
}

int reverselink(int n, int k, link links[])
{
    int i, j;
    link temp;
    for(i = 0; i < n / k; i++){
        for(j = i * k; j < i * k + k / 2; j++){
            temp = links[j];
            links[j] = links[i * k + (i+1) * k  - j - 1];
            links[i * k + (i+1) * k  - j - 1] = temp;
        }
    }
    return 0;
}

int printlink(int n, link links[])
{
    int i;
    for(i = 0; i < n - 1; i++)
        printf("%05d %d %05d\n", links[i].addr, links[i].data, links[i + 1].addr);
    printf("%05d %d -1\n", links[n - 1].addr, links[n - 1].data);
    return 0;
}
