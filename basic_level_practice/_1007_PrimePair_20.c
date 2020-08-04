/*
1007 素数对猜想 （20 分）

让我们定义d​n​​为：d​n​​=p​n+1​​−p​n​​，其中p​i​​是第i个素数。显然有d​1​​=1，且对于n>1有d​n​​是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10​5​​)，请计算不超过N的满足猜想的素数对的个数。
输入格式:

输入在一行给出正整数N。
输出格式:

在一行中输出不超过N的满足猜想的素数对的个数。
输入样例:

20

输出样例:

4

*/

/*
注意素数的查找方法，一步步找很可能会超时
*/
#include<stdio.h>
#include<string.h>

int main()
{
    int n,k,prime,nprime;
    int i,j,f;
    scanf("%d",&n);
    k==0;prime=3;nprime=3;

    for(i=5;i<=n;i+=2){
        f=0;
        for(j=2;j*j<=i;j++){
            if(i%j==0){
                f=1;
                break;
            }
        }
        if(f==0){
            nprime=i;
            if(nprime-prime==2)
                k++;
            prime=nprime;
        }
    }

    printf("%d\n",k);
    return 0;
}
