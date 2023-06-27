#include <stdio.h>
#include <stdlib.h>

int n;  //정점의 개수
int mat[1001][1001];
int visited_dfs[1001];
int visited_bfs[1001];
typedef struct {
	int data[1001];
	int front, rear;
}Queue;

void enqueue(Queue* q, int e) {
	q->rear = (q->rear + 1) % 1001;
	q->data[q->rear] = e;
}

int dequeue(Queue* q) {
	q->front = (q->front + 1) % 1001;
	return q->data[q->front];
}

int empty(Queue* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mat[i][j] = 0;
		}
	}
}

void insert_edge(int s,int e) {
	mat[s][e] = 1;
	mat[e][s] = 1;
}

void dfs(int v) {
	visited_dfs[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= n; i++) {
		if (!visited_dfs[i] && mat[v][i]) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	Queue q;
	q.front = 0, q.rear = 0;
	enqueue(&q, v);
	visited_bfs[v] = 1;
	printf("%d ", v);

	while (!empty(&q)) {
		int v = dequeue(&q);
		for (int i = 1; i <= n; i++) {
			if (!visited_bfs[i] && mat[v][i]) {
				visited_bfs[i] = 1;
				printf("%d ", i);
				enqueue(&q, i);
			}
		}
	}

}

int main()
{
	int m, v, a, b;
	scanf("%d %d %d", &n, &m, &v);
	init(); 
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insert_edge(a, b);
	}
	dfs(v);
	printf("\n");
	bfs(v);
}