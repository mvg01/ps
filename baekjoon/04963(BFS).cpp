#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int mat[51][51];
int visited[51][51];
int go[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1}, {1,0},{1,1} };

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			if (yy + go[i][0] >= 0 && yy + go[i][0] < n && xx + go[i][1] >= 0 && xx + go[i][1] < m) {
				if (!visited[yy + go[i][0]][xx + go[i][1]] && mat[yy + go[i][0]][xx + go[i][1]]) {
					q.push({ yy + go[i][0] ,xx + go[i][1] });
					visited[yy + go[i][0]][xx + go[i][1]] = 1;
				}
			}
		}
	}
}

int main() {
	while (1) {
		init();
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}
		int res = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && mat[i][j]) {
					bfs(i, j);
					res++;
				}
			}
		}
		cout << res << '\n';
	}
}