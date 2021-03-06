/*
1014 福尔摩斯的约会 （20 分）

大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
输入格式：

输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。
输出格式：

在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。
输入样例：

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

输出样例：

THU 14:04
*/

/*
设计思路：
1.确定星期几：第一个和第二个字符串中第一次字母相同，范围是 A-G；
2.确定小时数：满足条件 1 后，继续在后续字符串中查找，范围是 0-9 和 A-N；条件 2 满足后即可跳出循环，以防止输出再次满足条件的信息；
3.确定分钟数：第三和第四个字符串第一次字母相同，范围 A-Z 和 a-z；
4.小时和分钟要补零
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char week[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    char s[4][61];
    int i,j;
    for(i=0;i<4;i++){
        scanf("%s",s[i]);
    }
    j=0;
    for(i=0;(i<strlen(s[0])&&i<strlen(s[1]));i++){
        if(j==1&&s[0][i]==s[1][i]){
            if(s[0][i]>='A'&&s[0][i]<='N'){
                printf(" %02d",s[0][i]-'A'+10);
                j++;
            }
            if(s[0][i]>='0'&&s[0][i]<='9'){
                printf(" %02d",s[0][i]-'0');
                j++;
            }
        }
        if(j==0&&s[0][i]==s[1][i]&&(s[0][i]>='A'&&s[0][i]<='G')){
            printf("%s",week[s[0][i]-'A']);
            j++;
        }
        if(j>1) break;
    }
    for(i=0;(i<strlen(s[2])&&i<strlen(s[3]));i++){
        if(s[2][i]==s[3][i]&&((s[2][i]>='A'&&s[2][i]<='Z')||(s[2][i]>='a'&&s[2][i]<='z'))){
            printf(":%02d\n",i);
            break;
        }
    }
    return 0;
}
