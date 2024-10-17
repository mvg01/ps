#include <iostream>
using namespace std;

int n, m, res = 0;
char mat[601][601];
int visited[601][601];
int go[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (mat[y][x] == 'P')
		res++;

	for (int i = 0; i < 4; i++) {
		int yy = y + go[i][1];
		int xx = x + go[i][0];
		if (yy >= 0 && yy < n && xx >= 0 && xx < m) {
			if (!visited[yy][xx] && mat[yy][xx] != 'X') {
				visited[yy][xx] = 1;
				dfs(yy, xx);
			}
		}
	}
}

int main()
{
	int y, x;  //도연의 위치
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'I') {
				y = i;
				x = j;
			}
			visited[i][j] = 0;
		}
	}
	dfs(y, x);
	if (res == 0)
		cout << "TT";
	else
		cout << res;
}