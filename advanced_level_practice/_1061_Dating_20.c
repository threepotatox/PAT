/*
 * 题目大意：
 * [1014 福尔摩斯的约会](https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560)
 *
 * 设计思路：
 * [1014 福尔摩斯的约会（C语言）](https://blog.csdn.net/huaxuewan/article/details/86495564)
 * 1. 确定星期几：第一个和第二个字符串中第一次字母相同，范围是 A-G；
 * 2. 确定小时数：满足条件 1 后，继续在后续字符串中查找，范围是 0-9 和 A-N；条件 2 满足后即可跳出循环，以防止输出再次满足条件的信息；
 * 3. 确定分钟数：第三和第四个字符串第一次字母相同，范围 A-Z 和 a-z；
 * 4. 小时和分钟要补零
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	char s1[100], s2[100], s3[100], s4[100];
	int d, h, m;
	int i, j, len;

	scanf("%s%s%s%s", s1, s2, s3, s4);

	len = ((i = strlen(s1)) < (j = strlen(s2))) ? i : j;
	for (i = 0; i < len; i++) {
		if (s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G')) {
			d = s1[i] - 'A';
			break;
		}
	}
	for (i = i + 1; i < len; i++) {
		if (s1[i] == s2[i]) {
		       if (s1[i] >= 'A' && s1[i] <= 'N') {
				h = s1[i] - 'A' + 10;
				break;
		       }
		       if (s1[i] >= '0' && s1[i] <= '9') {
			       h = s1[i] - '0';
			       break;
		       }
		}
	}
	len = ((i = strlen(s3)) < (j = strlen(s4))) ? i : j;
	for (i = 0; i < len; i++) {
		if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))) {
			m = i;
			break;
		}
	}

	printf("%s %02d:%02d", week[d], h, m);
	
	return 0;
}
