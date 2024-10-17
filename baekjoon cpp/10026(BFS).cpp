#include <iostream>
#include <queue>
using namespace std;

int n;
char mat[101][101];
int visited[101][101];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int res1 = 0, res2 = 0;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 'G')   //초록색을 빨간색으로 바꿔버림
				mat[i][j] = 'R';
			visited[i][j] = 0;
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] < 0 || yy + dy[i] >= n || xx + dx[i] < 0 || xx + dx[i] >= n)
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] == mat[y][x] && !visited[yy + dy[i]][xx + dx[i]]) {
				visited[yy + dy[i]][xx + dx[i]] = 1;
				q.push({ yy + dy[i],xx + dx[i] });
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
		for (int j = 0; j < n; j++) 
			visited[i][j] = 0;
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				res1++;
			}
		}
	}
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				res2++;
			}
		}
	}
	cout << res1 << ' ' << res2;
}
