/*
设计思路：
1.难点在于处理好读入，数据用结构体存一下
2.readanswer() 读取答案，读取答案过程利用位运算让其转换为 int 型，便于计算比较。这样的话“正确选型个数”实际上用不到，当废弃值处理即可
*/

#include <stdio.h>

struct question {
	int score;
	int answer;
	int wrong;
};

int readanswer();

int main()
{
	struct question questions[100];
	int n, m;
	int tmp, score, max = 0;
	int i, j;
	char ch;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &questions[i].score, &tmp);
		questions[i].answer = readanswer();
		questions[i].wrong = 0;
	}
	for (i = 0; i < n; i++) {
		score = 0;
		for (j = 0; j < m; j++) {
			while ((ch = getchar()) != '(')
				continue;
			if (readanswer() == questions[j].answer)
				score += questions[j].score;
			else if (++questions[j].wrong > max)
				max = questions[j].wrong;
		}
		printf("%d\n", score);
	}

	if (max == 0) {
		printf("Too simple\n");
	} else {
		printf("%d", max);
		for (i = 0; i < m; i++)
			if (questions[i].wrong == max)
				printf(" %d", i + 1);
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
