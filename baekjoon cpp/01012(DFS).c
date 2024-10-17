#include <stdio.h>
#include <stdlib.h>

int x_move[4] = { 0,0,1,-1 };
int y_move[4] = { 1,-1,0,0 };
int visited[51][51];
int adj_mat[51][51];

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = 0;
			adj_mat[i][j] = 0;
		}
	}
}

void dfs(int x, int y) { 
	visited[x][y] = 1;
	int xplus, yplus;
	for (int i = 0; i < 4; i++) {
		xplus = x_move[i] + x;
		yplus = y_move[i] + y; {
			if (visited[xplus][yplus] == 0 && adj_mat[xplus][yplus] == 1)
				dfs(xplus, yplus);
		}
	}
}

int main()
{
	int t, n, m, k, a, b, res;
	scanf("%d", &t);
	while (t--) {
		res = 0;
		init();
		scanf("%d %d %d", &n, &m, &k);   //n->세로, m->가로
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);      //입력은 가로(행), 세로(열) 이므로
			adj_mat[b][a] = 1;           //좌표 순서 주의
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (adj_mat[j][i] == 1 && visited[j][i] == 0) {  
					dfs(j, i);
					res++;
				}
			}
		}
		printf("%d\n", res);
	}
}