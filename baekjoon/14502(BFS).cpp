#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int mat[8][8];
int mat2[8][8];
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };  //북 동 남 서 
int res = 0;
int safe = 0;

int bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat2[i][j] = mat[i][j];
			if (mat2[i][j] == 2) 
				q.push({ i,j });
		}
	}
	int vir = 0;

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (yy + go[i][0] >= 0 && yy + go[i][0] < n && xx + go[i][1] >= 0 && xx + go[i][1] < m) {
				if (mat2[yy + go[i][0]][xx + go[i][1]] == 0) {
					q.push({ yy + go[i][0] ,xx + go[i][1] });
					vir++;
					mat2[yy + go[i][0]][xx + go[i][1]] = 2;
				}
			}
		}
	}
	return vir;
}

void bt(int cnt) {
	if (cnt == 3) {
		res = max(safe - bfs() - 3, res); //안전지역에서 3개가 벽이 되므로
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0) {
				mat[i][j] = 1;
				bt(cnt + 1);
				mat[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 0)
				safe++;
		}
	}
	bt(0);
	cout << res;
}