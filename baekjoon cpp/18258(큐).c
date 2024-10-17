#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {  //큐 구조체
	int front;
	int rear;
	int* data;
}Queue;

void init(Queue *q,int n){
	q->front = -1;
	q->rear = -1;
	q->data = (int*)malloc(sizeof(int) * (n + 1));
}
void push(Queue* q,int e) {
	q->data[++(q->rear)] = e;
}
void pop(Queue* q) {
	if (empty(q))
		printf("-1\n");
	else {
		printf("%d\n", q->data[++(q->front)]);
	}
}
void size(Queue* q) {
	printf("%d\n", q->rear - q->front);
}
int empty(Queue* q) {
	if (q->rear == q->front) 
		return 1;
	else 
		return 0;
}
void front(Queue* q) {
	if (empty(q) == 1)
		printf("-1\n");
	else
		printf("%d\n", q->data[q->front + 1]);
}
void back(Queue* q) {
	if (empty(q) == 1)
		printf("-1\n");
	else
		printf("%d\n", q->data[q->rear]);
}

int main()
{
	int n, e;
	char m[9];
	Queue q;
	scanf("%d", &n);
	init(&q, n);
	while (n--)
	{
		scanf("%s", m);
		if (strcmp(m, "push") == 0) {
			scanf("%d", &e);
			push(&q, e);
		}
		else if (strcmp(m, "pop") == 0) 
			pop(&q);
		else if (strcmp(m, "size") == 0)
			size(&q);
		else if (strcmp(m, "empty") == 0) {
			if (empty(&q) == 1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(m, "front") == 0)
			front(&q);
		else if (strcmp(m, "back") == 0)
			back(&q);
	}
	free(q.data);
}
