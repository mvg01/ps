#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, d;  //0북, 1동, 2남, 3서
int mat[51][51];
int visited[51][51];
int r, c;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
//북,동,남,서  

void dfs(int y,int x, int res) {

	//cout << y << ' ' << x << '\n';
	for (int i = 0; i < 4; i++) {

		int dd = (d + 3 - i) % 4;  //d가 0이면 3부터 확인
		int yy = dy[dd] + y;
		int xx = dx[dd] + x;

		if (yy >= n || yy < 0 || xx >= m || xx < 0)
			continue;

		if (mat[yy][xx] == 0 && !visited[yy][xx]) {
			visited[yy][xx] = 1;
			d = dd;  //바뀐 방향 적용
			dfs(yy, xx, res + 1);
		}
	}
	
	//여기까지 왔을 때 청소되지 않은 빈칸은 없는 것이다.
	//따라서 청소 수에 카운트하지 않는다.
	//바라보는 방향 기준 후진 할 수 있다면 하고 불가능하면 작동 종료
	if (d == 0) {
		if (y + 1 < n) {
			if (!mat[y + 1][x]) {
				visited[y + 1][x] = 1;
				dfs(y + 1, x, res);
			}
		}
	}
	else if (d == 1) {
		if (x - 1 >= 0) {
			if (!mat[y][x - 1]) {
				visited[y][x - 1] = 1;
				dfs(y, x - 1, res);
			}
		}
	}
	else if (d == 2) {
		if (y - 1 >= 0) {
			if (!mat[y - 1][x]) {
				visited[y - 1][x] = 1;
				dfs(y - 1, x, res);
			}
		}
	}
	else if (d == 3) {
		if (x + 1 < m) {
			if (!mat[y][x + 1]) {
				visited[y][x + 1] = 1;
				dfs(y, x + 1, res);
			}
		}
	}
	
	//후진 불가능한 상태
	cout << res;
	exit(0);
}

int main()
{
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			visited[i][j] = 0;
		}
	}
	//청소 시작!!
	visited[r][c] = 1;
	dfs(r, c, 1);
}