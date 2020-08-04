/*
 * 设计思路：
 * 利用队列进行层序遍历，利用栈进行 Z 字型输出
 * * 层序遍历，正常顺序入队
 * * 偶数层出队，直接入栈，不打印
 * * 奇数层出队前，先让栈中所有元素出栈，再出队并打印
 * * 若树的最大层数为偶数，节点均出队后，栈中会有剩余元素未输出，所以用队列遍历完后，要把栈中剩余元素打印
 */

#include <stdio.h>

struct node {
	int iroot, left, right;
	int level;
};

int in[35], post[35];
int stack[35], scnt;
struct node queue[35];
int qcnt, front, rear;

int main(void)
{
	int n;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &in[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &post[i]);

	queue[0].iroot = n - 1;
	queue[0].left = 0;
	queue[0].right = n - 1;
	queue[0].level = 0;
	front = 0;
	rear = 1;
	qcnt = 1;

	while (qcnt) {
		int iroot = queue[front].iroot;
		int left = queue[front].left;
		int right = queue[front].right;
		int level = queue[front].level;
		if (queue[front].level % 2 == 0) {
			stack[scnt] = post[iroot];
			scnt++;
		} else {
			for (i = scnt - 1; i >= 0; i--)
				printf("%s%d", stack[i] == post[n - 1] ? "" : " ", stack[i]);
			scnt = 0;

			printf(" %d", post[iroot]);
		}
		front++;
		qcnt--;
		int index = left;
		while (in[index] != post[iroot])
			index++;
		if (left <= index - 1) {
			queue[rear].iroot = iroot - 1 + index - right;
			queue[rear].left = left;
			queue[rear].right = index - 1;
			queue[rear].level = level + 1;
			rear++;
			qcnt++;
		}
		if (index + 1 <= right) {
			queue[rear].iroot = iroot - 1;
			queue[rear].left = index + 1;
			queue[rear].right = right;
			queue[rear].level = level + 1;
			rear++;
			qcnt++;
		}
	}
	for (i = scnt - 1; i >= 0; i--)
		printf("%s%d", stack[i] == post[n - 1] ? "" : " ", stack[i]);

	return 0;
}
