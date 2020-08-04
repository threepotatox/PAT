/*
 * 设计思路：
 * 1. 维护一个队列，实现层序遍历，队列的节点是一颗子树：
 *     * 队列节点 node，指向后序遍历和中序遍历子数组的指针，两个子数组相等的长度（以此代表一颗子树）
 * 2. 初始化整颗树入队：
 *     * 节点出队，节点的后序遍历数组的最后一位得到根节点；再根据中序遍历数组求得左右子树入队
 *     * 队列空，层序遍历完成
 */

#include <stdio.h>

struct node {
	int *post, *in;
	int length;
};

struct queue {
	struct node *nodes[31];
	int front, rear, count;
};

void enqueue(struct queue *q, struct node *m)
{
	q->nodes[q->rear] = m;
	q->rear++;
	q->count++;
}

struct node *dequeue(struct queue *q)
{
	struct node *m = q->nodes[q->front];
	q->front++;
	q->count--;
	return m;
}

int main(void)
{
	int n, post[31] = {0}, in[30] = {0};
	struct queue q = {0};
	int root, index, count;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", post + i);
	for (i = 0; i < n; i++)
		scanf("%d", in + i);

	struct node nodes[31] = {{post, in , n}}, *p = nodes, *m;
	enqueue(&q, p++);
	for (count = 0; q.count; count++) {
		m = dequeue(&q);
		root = m->post[m->length - 1];

		for (index = 0;
			index < m->length && m->in[index] != root;
			index++)
			;

		p->post = m->post;
		p->in = m->in;
		p->length = index;
		if (p->length != 0)
			enqueue(&q, p++);

		p->post = m->post + index;
		p->in = m->in + index + 1;
		p->length = m->length - index - 1;
		if (p->length != 0)
			enqueue(&q, p++);

		printf("%d%c", root, (count == n - 1) ? '\0' : ' ');
	}

	return 0;
}
