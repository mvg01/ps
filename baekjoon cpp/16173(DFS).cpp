#include <iostream>
using namespace std;

int n;
int mat[4][4];
int visited[4][4];
int go[2][2] = { {1,0},{0,1} };
bool chk = 0;

void dfs(int y, int x) {
	if (y == n && x == n) {
		chk = 1;
		return;
	}

	visited[y][x] = 1;
	int yy = y, xx = x;
	for (int i = 1; i <= 2; i++) {
		if (i == 1)
			yy += mat[y][x];
		else if (i == 2)
			xx += mat[y][x];
		
		if (yy >= 1 && yy <= n && xx >= 1 && xx <= n) {
			if (!visited[yy][xx]) {
				visited[yy][xx] = 1;
				dfs(yy, xx);
				visited[yy][xx] = 0;
			}
		}

		if (i == 1)
			yy -= mat[y][x];
		else if (i == 2)
			xx -= mat[y][x];
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			visited[i][j] = 0;
		}
	}
	dfs(1, 1);
	if (chk)
		cout << "HaruHaru";
	else
		cout << "Hing";
}