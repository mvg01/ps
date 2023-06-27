#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
	int n;
	int mat[101][101];
}GraphType;

void init(GraphType* g, int k) {
	g->n = k;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			g->mat[i][j] = 0;
		}
	}
}

void insert_edge(GraphType* g, int s,int e) {
	g->mat[s][e] = 1;
	g->mat[e][s] = 1;
}

int visited[101];
int cnt = 0;
void dfs(GraphType* g, int v) {
	visited[v] = 1;
	//printf("%d ", v);
	for (int i = 1; i <= g->n; i++) {
		if (!visited[i] && g->mat[v][i]) {
			dfs(g, i);
			cnt++;
		}
	}
}

int main()
{
	GraphType g;
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	init(&g, n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insert_edge(&g, a, b);
	}
	dfs(&g, 1);
	printf("%d", cnt);
}