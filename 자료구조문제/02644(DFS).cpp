#include <iostream>
using namespace std;

int n, a, b, res = 100000;
int mat[101][101];
int visited[101] = { 0 };

void dfs(int c, int cnt) {
	if (c == a) {
		res = min(res, cnt);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (mat[c][i] == 1 && !visited[i]) {  //가족으로 연결되어 있다면
			visited[i] = 1;
			dfs(i, cnt + 1);  //i의 가족 탐색 , 촌수 추가
		}
	}
}

int main()
{
	int m, x, y;
	cin >> n;
	cin >> a >> b;
	cin >> m;
    
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

	visited[b] = 1;
	dfs(b, 0);
	if (res != 100000)
		cout << res;
	else
		cout << -1;
}