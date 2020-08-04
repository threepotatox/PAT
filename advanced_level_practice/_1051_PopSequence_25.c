/*
 * 设计思路：
 * 栈的模拟，对于每个出栈序列：
 * * 每读取到一个出栈数字，则将此数字及小于此数字的数入栈，入栈需满足：
 *     * 栈顶 top 不能超过容量 M
 *     * count 表示入栈数字 1, 2, 3, ..., N 应小于等于 N
 *     * 栈顶元素小于读取到的出栈数字 num，则说明 count 表示的数字还未入栈
 * * 栈顶元素等于读取到的出栈数字，则栈顶出栈，读取下一个出栈数字继续判断
 * * 若不能出栈，则读取剩余出栈元素并结束循环
 * * 栈中元素为空输出 "YES"，否则输出 "NO"
 */

#include <stdio.h>

int main(void)
{
	int m, n, k;
	int stack[1000] = {-1}, top = 1;
	int i, j, num, count;

	scanf("%d %d %d", &m, &n, &k);
	for (i = 0; i < k; i++) {
		top = 1;
		count = 1;
		for (j = 0; j < n; j++) {
			scanf("%d", &num);
			while (top <= m && count <= n && stack[top - 1] < num) {
				stack[top] = count;
				count++;
				top++;
			}
			if (stack[top - 1] == num) {
				top--;
			} else {
				scanf("%*[^\n]");
				break;
			}
		}
		if (top > 1) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}

	return 0;
}
