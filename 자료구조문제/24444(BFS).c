#include <stdio.h>
#include <stdlib.h>

int n;
int* visited;
int* res;
int* size;
int* mat[100001];

void init() {
	visited = (int*)malloc(sizeof(int) * (n + 1));
	res = (int*)malloc(sizeof(int) * (n + 1));
	size = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
		res[i] = 0;
		size[i] = 0;
	}
}
void insert(int s, int e) {
	mat[s] = (int*)realloc(mat[s], sizeof(int) * (size[s] + 1));
	mat[e] = (int*)realloc(mat[e], sizeof(int) * (size[e] + 1));
	mat[s][size[s]++] = e;
	mat[e][size[e]++] = s;
}

typedef struct Queue {
	int* data;
	int front, rear, size;
}Queue;
void initque(Queue* q) {
	q->data = (int*)malloc(sizeof(int) * (n + 1));
	q->front = 0;
	q->rear = 0;
	q->size = n;
}
void enqueue(Queue* q, int item) {
	q->rear = (q->rear + 1) % q->size;
	q->data[q->rear] = item;
}
int dequeue(Queue* q) {
	q->front = (q->front + 1) % q->size;
	return q->data[q->front];
}
int isempty(Queue* q) {
	return (q->rear == q->front);
}

void bfs(int v)
{
	Queue q;
	initque(&q);
	visited[v] = 1;
	enqueue(&q, v);
	int popdata, idx = 1;
	res[v] = idx++;

	while (!isempty(&q))
	{
		popdata = dequeue(&q);
		for (int i = 0; i < size[popdata]; i++)
		{
			if (!visited[mat[popdata][i]]) {
				visited[mat[popdata][i]] = 1;
				res[mat[popdata][i]] = idx++;
				enqueue(&q, mat[popdata][i]);
			}
		}
	}
	free(q.data);
}

int static c(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
}

int main() 
{
	int m, r, a, b;
	scanf("%d %d %d", &n, &m, &r);
	init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insert(a, b);
	}
	for (int i = 1; i <= n; i++)
		qsort(mat[i], size[i], sizeof(mat[i][0]), c);

	bfs(r);
	for (int i = 1; i <= n; i++)
		printf("%d\n", res[i]);

	free(visited);
	free(res);
	free(size);
	for (int i = 1; i <= n; i++) 
		free(mat[i]);
}