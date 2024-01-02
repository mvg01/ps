#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mat[101][101];
int visited[101][101];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int n, m, k, res = 0;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			visited[i][j] = 0;
	}
}

void bfs(int y,int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visited[y][x] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] >= n || yy + dy[i] < 0 || xx + dx[i] >= m || xx + dx[i] < 0)
				continue;
			if (visited[yy + dy[i]][xx + dx[i]] == 1)
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] == 1) {
				q.push({ yy + dy[i], xx + dx[i] });
				visited[yy + dy[i]][xx + dx[i]] = 1;
			}
		}
	}
	res = max(res, cnt);
}

int main()
{
	int x, y;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		mat[y - 1][x - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) {
				init();
				bfs(i, j);
			}
		}
	}

	cout << res;
}