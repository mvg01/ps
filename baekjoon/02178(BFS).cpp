#include <iostream>
#include <queue>
using namespace std;

int x_move[4] = { 1,0,0,-1 };
int y_move[4] = { 0,1,-1,0 };
int mat[101][101];
int visited[101][101] = { 0 };
int res[101][101] = { 0 };
int n, m;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	res[x][y] = 1;

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xplus = xx + x_move[i];
			int yplus = yy + y_move[i];
			if (xplus < n && yplus < m) {
				if (visited[xplus][yplus] == 0 && mat[xplus][yplus] == 1) {
					q.push({ xplus,yplus });
					visited[xplus][yplus] = 1;
					res[xplus][yplus] = res[xx][yy] + 1;
				}
			}
		}
	}
}

int main()
{
	char s[101];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			mat[i][j] = s[j] - '0';
	}
	bfs(0, 0);
	cout << res[n - 1][m - 1];
}