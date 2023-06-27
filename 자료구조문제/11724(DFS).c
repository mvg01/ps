//연결요소: 정점에 이어진 간선을 따라가다가 더 이상 갈 곳이 없으면 그것이 한 개의 연결 요소이다. 
#include <stdio.h>
#include <stdlib.h>

int mat[1001][1001];

void init(int n) {
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

int visited[101];
int cnt = 0;
void dfs(int v, int n) {
	visited[v] = 1;
	//printf("%d ", v);
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && mat[v][i]) {
			dfs(i, n);
		}
	}
}

int main()
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insert_edge(a, b);
	}
	for (int i = 1; i <= n; i++) { //모든 연결 요소 별로 완전 탐색
		if (!visited[i]) { //방문하지 않았던 것 들 중에
			dfs(i, n);
			cnt++;
		}
	}
	printf("%d", cnt);
}