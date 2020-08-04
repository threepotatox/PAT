/*
 * 设计思路：
 * * 预先假设所有键盘都坏了，根据字符串标记好的键
 * * 只要有一次 （连续相同字符）% K != 0 就说明此键是好的
 *
 * 注意：
 * * 如果预先假设键盘良好，进而标记坏键，其实依旧需要标记遍历过程中发现的好键，例如，输入 2 abaa
 * * 仅标记坏键的话，会误判 a 为坏键
 * * 这是因为不能依据一次坏记录，就判断按键已坏，所有次记录都是坏的，才能判断已坏，
 * * 而判断好键则相反，一次好记录就足以说明是好键
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1010] = {'\0'};
	int k;
	int flag[128] = {0};// 0 huai le
	int i, j, len;

	scanf("%d %s", &k, str);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		j = i + 1;
		while (j < len && str[j] == str[i])
			j++;
		if ((j - i) % k != 0)
			flag[str[i]] = 1;
		i = j - 1;
	}
	int out[128] = {0};
	for (i = 0; i < len; i++) {
		if (flag[str[i]] == 0 && out[str[i]] == 0) {
			printf("%c", str[i]);
			out[str[i]] = 1;
		}
	}
	puts("");
	for (i = 0; i < len; i++) {
		printf("%c", str[i]);
		if (flag[str[i]] == 0)
			i += (k - 1);
	}
	return 0;
}
