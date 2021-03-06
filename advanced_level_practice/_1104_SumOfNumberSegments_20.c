/*
    for(i = 0; i < n; i++)
            scanf("%f", num + i);
    for(i = 0; i < n; i++){
            tem = 0.0;
            for(j = i; j < n; j++){
        	     tem += num[j];
       		     sum += tem;
	     }
     }
设计思路：
1.方法一利用双重循环加和
2.方法二是直接根据数字的位置，计算这个数字被重复加了几次，
设数字个数为 n，数字位于第 i 位，则：
重复次数 = i * (n - i)

和乙级相比，这道题因为 [Ruihan Zheng，https://blog.zhengrh.com/post/about-double/](https://blog.zhengrh.com/post/about-double/) 大佬的反馈，计算结果需要更高的精度，把浮点数转换成 long long 长整型计算
*/

#include <stdio.h>

int main(void)
{
	int n;
	double num;
	long long sum = 0;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lf", &num);
		sum += ((long long)(num * 1000)) * (i + 1) * (n - i);
	}
	printf("%.2lf\n", sum / 1000.0);

	return 0;
}
