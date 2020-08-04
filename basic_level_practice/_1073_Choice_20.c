/*
 * 设计思路：
 * 1.输入读取同 1058 相同，直接用
 * 2.计分标准变化，如何判断得分情况成为关键，利用位运算 ^ 和 | 来判断
 * 3.异或值 = 学生答案 ^ 标准答案
 * 异或值 == 0 ，答案正确
 * 	异或值 != 0 ，说明学生答案少选或错选
 * 		少选的情况下，少选位上的异或值为 1，此时 (异或值 | 标准答案) 一定等于 (标准答案)
 * 			错选的情况下，错选位上的异或值为 1，此时 (异或值 | 标准答案) 一定大于 (标准答案)
 *
 *再次感谢 OliverLew (LuXu) 大佬：
 *https://oliverlew.github.io/PAT/Basic/1073.html
 *
 */

#include <stdio.h>

struct question {
	int score;
	int answer;
	int wrong[5];
};

int readanswer();

int main()
{
	struct question questions[100];
	int n, m;
	int tmp, answer, answer_xor, max = 0;
	int i, j, k;
	double score;
	char ch;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &questions[i].score, &tmp);
		questions[i].answer = readanswer();
		for (j = 0; j < 5; j++)
			questions[i].wrong[j] = 0;
	}
	for (i = 0; i < n; i++) {
		score = 0.0;
		for (j = 0; j < m; j++) {
			while ((ch = getchar()) != '(')
				continue;
			answer = readanswer();
			answer_xor = (answer ^ questions[j].answer);
			if (answer_xor == 0) {
				score += questions[j].score;
			} else if ((answer_xor | questions[j].answer) == questions[j].answer) {
				score += questions[j].score / 2.0;
				tmp = questions[j].answer - answer;
				for (k = 0; k < 5; k++) {
					if (tmp % 2)
						if (++questions[j].wrong[k] > max)
							max = questions[j].wrong[k];
					tmp >>= 1;
				}
			} else if ((answer_xor | questions[j].answer) > questions[j].answer) {
				tmp = answer_xor ;
				for (k = 0; k < 5; k++) {
					if (tmp % 2)
						if (++questions[j].wrong[k] > max)
							max = questions[j].wrong[k];
					tmp >>= 1;
				}
			}
		}
		printf("%.1lf\n", score);
	}

	if (max == 0) {
		printf("Too simple\n");
	} else {	
		for (i = 0; i < m; i++) {
			for (j = 0; j <  5; j++)
				if (questions[i].wrong[j] == max)
					printf("%d %d-%c\n", max, i + 1, 'a' + j);
		}	
	}

	return 0;
}

int readanswer()
{
	int answer = 0;
	char ch;
	
	while ((ch = getchar()) && ch != '\n' && ch != ')')
		if (islower(ch))
			answer |= 1 << (ch - 'a');

	return answer;
}
