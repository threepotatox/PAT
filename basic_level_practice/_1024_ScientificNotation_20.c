/*
设计思路：
1.数字的正负号决定普通数字的正负
2.指数的正负号决定小数点的移动
*/

#include <stdio.h>
#include <string.h>

int movepoint(char n[], int index);/*当指数为正，向右移动小数点*/
/*此函数用 '\0' 判断补 0 和输出小数点，数组至少需要 10002 个空间，定义 n[10003]*/

int rightprint(char n[], int index);
/*此函数利用指针直接循环输出，数组空间达题目要求即可，定义 n[10000]（参考源码来自https://oliverlew.github.io/PAT/Basic/1024.html）*/

int main()
{
    int index;
    char n[10003] = {'\0'};
    scanf("%[^E]E%d", n, &index);
    if(n[0] == '-') printf("-");
    if(index >= 0){
        movepoint(n, index);
        printf("%s\n", n+1);
    }
    else{
        printf("0.");
        for(index++; index; index++){
            printf("0");
        }
        printf("%c%s\n", n[1], n+3);
    }
    return 0;
}

int movepoint(char n[], int index)
{
    char *p = n+2;
    for(; index; index--){
        if(*(p+1) != '\0') *p = *(p+1);        
        else               *p = '0';
        p++;
        *p = '.';
    }
    if(*(p+1) == '\0') *p = '\0';
    return 0;
}

int rightprint(char n[], int index)
{
    char *p = n+1;
    putchar(*p);
    for(p += 2; index; index--){
        putchar(*p ? *p++ : '0');
    }
    if(*p)
    {
        putchar('.');
        while(*p) putchar(*p++);
    }
}
