#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int mat[101][101];
int visited[101][101];
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };  //북 동 남 서 
int res[101] = { 0 };

void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) 
			visited[i][j] = 0;
	}
}

void bfs(int y, int x,int h) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (yy + go[i][0] >= 0 && yy + go[i][0] < n && xx + go[i][1] >= 0 && xx + go[i][1] < n) {
				if (!visited[yy + go[i][0]][xx + go[i][1]] && mat[yy + go[i][0]][xx + go[i][1]] > h) {
					q.push({ yy + go[i][0] ,xx + go[i][1] });
					visited[yy + go[i][0]][xx + go[i][1]] = 1;
				}
			}
		}
	}
}

int main()
{
	int big = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			big = max(big, mat[i][j]);
		}
	}

	int island = 0;
	for (int k = 0; k <= big; k++) { //물에 잠기지 않을 수 있다.
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && mat[i][j] > k) {
					bfs(i, j, k);
					res[k]++;
				}
			}
		}
		//cout << res[k] << ' ';
		island = max(res[k], island);
	}
	cout << island;
}
