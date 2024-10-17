#include <iostream>
#include <queue>
using namespace std;

int n, m;
int mat1[31][31];
int mat2[31][31];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
bool visited[31][31] = { 0, };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> mat1[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> mat2[i][j];
	}
}
void bfs(int y, int x) {
	int point = mat2[y][x];  // 백신 맞고 바뀐 곳
	int temp = mat1[y][x];  // 백신 맞기 전, 기존의 수
	mat1[y][x] = point;
	bool vv[31][31] = { 0, };
	queue<pair<int, int>>q;
	q.push({ y,x });
	vv[y][x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (vv[yy + dy[i]][xx + dx[i]])
				continue;
			if (yy + dy[i] >= n || yy + dy[i] < 0 || xx + dx[i] < 0 || xx + dx[i] >= m)
				continue;
			if (mat1[yy + dy[i]][xx + dx[i]] == temp) {
				vv[yy + dy[i]][xx + dx[i]] = true;
				q.push({ yy + dy[i],xx + dx[i] });
				mat1[yy + dy[i]][xx + dx[i]] = point;
			}
		}
	}
}

// 풀이과정: mat1과 mat2가 다른 부분이 보이면, 최초 한 번 mat1에도 백신을 놓아준다.
// 두 번이상 다른 부분이 생기면 NO, 백신을 놔주고 다른 칸이 있다면 NO
void solve() {  
	bool chk = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat1[i][j] != mat2[i][j] && !visited[i][j]) {
				bfs(i, j);
				if (chk) {
					cout << "NO";
					return;
				}
				chk = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat1[i][j] != mat2[i][j]) {
				cout << "NO";
				return;
			}
		}
	}
	cout << "YES";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}