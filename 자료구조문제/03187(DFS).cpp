#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char mat[251][251];
int visited[251][251];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int res_sheep = 0;
int res_wolf = 0;
int wolf, sheep;

void dfs(int y, int x) {

	if (mat[y][x] == 'v') 
		wolf++;
	
	else if (mat[y][x] == 'k') 
		sheep++;

	for (int i = 0; i < 4; i++) {
		if (y + dy[i] < 0 || y + dy[i] >= n || x + dx[i] < 0 || x + dx[i] >= m)
			continue;
		if (mat[y + dy[i]][x + dx[i]] !='#' && !visited[y + dy[i]][x + dx[i]]) {
			visited[y + dy[i]][x + dx[i]] = 1;
			dfs(y + dy[i], x + dx[i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mat[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && mat[i][j] != '#') {
				sheep = 0; wolf = 0;
				visited[i][j] = 1;
				dfs(i, j);
				if (sheep > wolf)
					res_sheep += sheep;
				else
					res_wolf += wolf;
			}
		}
	}
	cout << res_sheep << ' ' << res_wolf;
}