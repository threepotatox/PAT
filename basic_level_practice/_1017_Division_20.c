/*
设计思路：
用字符数组存储大数，用循环模拟除法运算
*/

#include <stdio.h>

int main()
{
    char a[1001] = {'\0'};
    int b,r,i,temp;
    scanf("%s %d", a, &b);
    r = 0;
    i = 0;
    while(a[i]){
        temp = r * 10 + (a[i] - '0');
        a[i] = (temp / b) + '0';
        r = temp % b;
        i++;
    }
    printf("%s %d\n",((a[0] == '0' && a[1] != '\0') ? (a+1) : (a)), r);
    return 0;
}   

