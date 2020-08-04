/*
 * 设计思路：
 * 依旧考察如何正确处理输入
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char password[21], try[21], c;

	scanf("%s %d", password, &n);
	while (getchar() != '\n')
		continue;

	while (n--) {
		scanf("%20[^\n]", try);
		c = ungetc(getchar(), stdin);
		if (!strcmp(try, "#") && c == '\n') {
			break;
		} else if (!strcmp(password, try) && c == '\n') {
			puts("Welcome in");
			break;
		} else {
			printf("Wrong password: %s", try);
			while (putchar(getchar()) != '\n')
				continue;
			if (!n)
				puts("Account locked");
		}
	}

	return 0;
}
