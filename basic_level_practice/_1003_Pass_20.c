/*
1003 我要通过！ （20 分）

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

    字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
    任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
    如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式：

每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。
输出格式：

每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。
输入样例：

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：

YES
YES
YES
YES
NO
NO
NO
NO

*/

/*
 * 感觉此题有点绕，仅提供本程序设计思路参考：
 * 1，字符串须含有 PAT ，相对顺序不变，P T 个数分别只有 1 个
 * 2，若是含其他字符只能是 A
 * 3，P 前面有 a 个 A，P T 间有 b 个 A，T 后面有 c 个 A，要满足 a*b=c（注意 b 不能为 0，否则不能满足条件1）
 * */

#include <stdio.h>
#include <string.h>

int main()
{
   int n,i,j,nump,numt,numa;
   char str[101];

   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
    scanf("%s",str);
    nump=0;numt=0;numa=0;
    for(j=0;j<strlen(str);j++)
    {
       if(nump==0&&numt>0)//如果先遇到 T，返回
          break;
       
       if(str[j]=='A')
          numa++;
       else if(str[j]=='P'&&nump==0)
            {numa++; nump=numa;}
       else if(str[j]=='T'&&numt==0)
             {numa++;numt=numa;}       
       else
          break;
    }
    if(j==strlen(str)&&(nump>0)&&(numt>0)&&(numt-nump-1)>0&&(nump-1)*(numt-nump-1)==(numa-numt))
    {
       printf("YES\n");
    }
    else
      printf("NO\n");
  
   }
   
   return 0;
}
