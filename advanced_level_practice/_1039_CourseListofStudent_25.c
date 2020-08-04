/*
 * 设计思路：
 * 1. 名字按照 26*26*26*10 映射为数字，用 id 数组记录每个人的序号，序号按照每个人的出现次序依次递增；
 * 2. 用结构体数组按照学生序号记录每位学生的选课情况；
 *     1. 有 2500 门课，直接用 char c[2500] 记录绝对超内存，所以用 1 bit 记录一门课，需要用位运算；
 *     2. 进行位运算时，可以把 char c[313] 看作 bit c[313][8]，两个维度的下标均从 0 开始，所以对于课程编号进行减 1 处理 course--；
 * 3. 按查询顺序输出；
 * 4. c[course >> 3] |= (128 >> (course & (8 - 1))：
 *     1. course >> 3，课程编号除以 8，得到 c[][] 一维下标
 *     2. course & ( 8 - 1)，课程编号对 8 取余后移位，相当于得到 c[][] 二维下标；
 *     3. c[course >> 3] |= (128 >> (course & (8 - 1))，移位运算，或运算，相当于把 c[][] 对应位赋值为 1；
 *
 * 注意：
 *     1. 题目中 40000 仅是需要查询的学生数目最大值，学生数目最大值依旧是 26*26*26*10，最开始结构数组只给了 40000，导致最后一个测试点段错误；
 *     2. 进行位运算时，可以把 char c[313] 看作 bit c[313][8]，两个维度的下标均从 0 开始，所以对于课程编号进行减 1 处理 course--，对位运算不熟悉，开始没有减 1 处理，结果都是错的；
 *     3. 是否还有其他思路记录课程信息？望大神告知！
 */

#include <stdio.h>

struct student {
	char c[313];
	int sum;
};

struct student stus[26 * 26 * 26 * 10 + 10] = {0};
int id[26 * 26 * 26 * 10 + 10] = {0}, count = 0;
int main(void)
{
	int n, k;
	int course, m;
	int i, j, v;
	char name[5];

	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++) {
		scanf("%d %d", &course, &m);
		course--;
		for (j = 0; j < m; j++) {
			scanf(" %s", name);
			int temp = toid(name);
			stus[temp].c[course >> 3] |= (128 >> (course & (8 - 1)));
			stus[temp].sum++;
		}
	}

	for (i = 0; i < n; i++) {
		scanf(" %s", name);
		int temp = toid(name);
		printf("%s %d", name, stus[temp].sum);
		for (j = 0; j < 313; j++) {
			for (v = 0; v < 8; v++) {
				if ((stus[temp].c[j] & (128 >> v)) != 0) {
					printf(" %d", j * 8 + v + 1);
				}
			}
		}
		printf("\n");
	}

	return 0;
}

int toid(char s[])
{
	int n = 0;
	int i = 0, temp = 0;
	
	for (i = 0; i < 3; i++) {
		n = n * 26 + (s[i] - 'A');
	}
	n = n * 10 + (s[i] - '0');
	if (id[n] == 0) {
		count++;
		id[n] = count;
	}
	
	return id[n];
}
