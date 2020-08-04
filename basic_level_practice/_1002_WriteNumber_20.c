/*
1002 写出这个数 （20 分）

读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：

每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100。
输出格式：

在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：

1234567890987654321123456789

输出样例：

yi san wu


*/

#include<stdio.h>
#include<string.h>

int main()
{
    int sum=0,i=0;
    char s[10][5]={{"ling"},{"yi"},{"er"},{"san"},{"si"},{"wu"},{"liu"},{"qi"},{"ba"},{"jiu"}};
    char str[110],num[110];
    scanf("%s",str);
    while(i<strlen(str))
    {
       sum=sum+(str[i]-'0');
       i++;
    }
    i=0;
    do
    {
       num[i]=(sum%10+'0');
       sum=sum/10;
       i++;
    }while(sum!=0);
    num[i]='\0';
    for(i=strlen(num)-1;i>0;i--)
    {
       printf("%s ",s[(num[i]-'0')]);
    }
    printf("%s\n",s[(num[i]-'0')]);
    
    return 0;
}
