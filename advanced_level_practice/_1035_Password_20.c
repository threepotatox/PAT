/*
 * 设计思路：
 * 将需要修改的密码，按题目要求修改后储存，计数输出；这里利用了三维数组，储存用户名和密码
 */

#include <stdio.h>

int main(void)
{
	char name[1000][2][11] = {'\0'};
	int n, count = 0;
	int i, flag;
	char *q = NULL, ch;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s ", name[count][0]);
		q = &name[count][1][0];
		flag = 0;
		while ((ch = getchar()) != '\n') {
			switch (ch) {
			case 'l':
				ch = 'L'; flag = 1;
				break;
			case 'O':
				ch = 'o'; flag = 1;
				break;
			case '1':
				ch = '@'; flag = 1;
				break;
			case '0':
				ch = '%'; flag = 1;
				break;
			}
			*q = ch;
			q++;
		}
		*q = '\0';
		if (flag) {
			count++;
		}
	}

	if (count) {
		printf("%d\n", count);
		for (i = 0; i < count; i++) {
			printf("%s %s\n", name[i][0], name[i][1]);
		}
	} else if (n == 1) {
		printf("There is 1 account and no account is modified\n");
	} else {
		printf("There are %d accounts and no account is modified\n", n);
	}

	return 0;
}
