#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
char mat[251][251];
int visited[251][251];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int res_sheep = 0;
int res_wolf = 0;

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	visited[y][x] = 1;
	int wolf = 0, sheep = 0;
	q.push({ y,x });
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		if (mat[yy][xx] == 'v')
			wolf++;
		else if (mat[yy][xx] == 'k')
			sheep++;

		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] < 0 || yy + dy[i] >= n || xx + dx[i] < 0 || xx + dx[i] >= m)
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] !='#' && !visited[yy + dy[i]][xx + dx[i]]) {
				visited[yy + dy[i]][xx + dx[i]] = 1;
				q.push({ yy + dy[i],xx + dx[i] });
			}
		}
	}
	if (sheep > wolf)
		res_sheep += sheep;
	else
		res_wolf += wolf;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mat[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && mat[i][j] != '#') {
				bfs(i, j);
			}
		}
	}
	cout << res_sheep << ' ' << res_wolf;
}