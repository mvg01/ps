#include <iostream>
#include <queue>
using namespace std;

int visited[501][501];
int mat[501][501];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int cnt = 0, res = 0;
int n, m;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			visited[i][j] = 0;
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	cnt++;
	int c = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] < 0 || yy + dy[i] >= n || xx + dx[i] < 0 || xx + dx[i] >= m)
				continue;
			if (visited[yy + dy[i]][xx + dx[i]])
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] == 1) {
				q.push({ yy + dy[i],xx + dx[i] });
				visited[yy + dy[i]][xx + dx[i]] = 1;
				c++;
			}
		}
	}
	res = max(res, c);
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			cin >> mat[i][j];
	}
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 && !visited[i][j])
				bfs(i, j);
		}
	}
	cout << cnt << '\n' << res;
}