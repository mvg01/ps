#include <stdio.h>
#include <stdlib.h>

int n;  //정점의 개수
int* mat[100001];
int* res;
int* size;
int* visited;
typedef struct {
	int *data;
	int front, rear;
}Queue;
void enqueue(Queue* q, int e) {
	q->rear = (q->rear + 1) % n;
	q->data[q->rear] = e;
}
int dequeue(Queue* q) {
	q->front = (q->front + 1) % n;
	return q->data[q->front];
}
int empty(Queue* q) {
	return (q->front == q->rear);
}

void init() {
	size = (int*)calloc(n + 1, sizeof(int));
	visited = (int*)calloc(n + 1, sizeof(int));
	res = (int*)calloc(n + 1, sizeof(int));
}

void insert(int s, int e) {
	mat[s] = (int*)realloc(mat[s], sizeof(int) * (size[s] + 1));
	mat[e] = (int*)realloc(mat[e], sizeof(int) * (size[e] + 1));
	mat[s][size[s]++] = e;
	mat[e][size[e]++] = s;
}

void bfs(int v) {
	Queue q;
	q.front = 0, q.rear = 0;
	q.data = (int*)malloc(sizeof(int) * (n + 1));
	enqueue(&q, v);
	visited[v] = 1;

	while (!empty(&q)) {
		v = dequeue(&q);  //부모노드

		for (int i = 0; i < size[v]; i++) {
			int w = mat[v][i];  //자식노드
			if (!visited[w]) {
				res[w] = v;     //부모노드 저장
				visited[w] = 1;
				enqueue(&q, w);
			}
		}
	}
	free(q.data);
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < size[i]; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

int main()
{	
	int a, b;
	scanf("%d", &n);
	init();
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		insert(a, b);
	}
	//print();
	bfs(1);

	for (int i = 2; i <= n; i++)
		printf("%d\n", res[i]);

	for (int i = 1; i <= n; i++)
		free(mat[i]);
}