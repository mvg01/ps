#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int mat[251][251];
int visited[251][251];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int res = 0;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		if (y + dy[i] < 0 || y + dy[i] >= n || x + dx[i] < 0 || x + dx[i] >= m)
			continue;
		if (mat[y + dy[i]][x + dx[i]] == 1 && !visited[y + dy[i]][x + dx[i]]) {
			visited[y + dy[i]][x + dx[i]] = 1;
			dfs(y + dy[i], x + dx[i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);
				res++;
			}
		}
	}
	cout << res;
}