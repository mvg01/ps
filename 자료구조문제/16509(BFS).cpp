#include <iostream>
#include <queue>
using namespace std;

int r1, c1, r2, c2;
int visited[10][9] = { 0, };
int dx[8] = { 3,3,2,-2,-3,-3,-2,2 };
int dy[8] = { -2,2,3,3,2,-2,-3,-3 };
vector<pair<int, int>>v[8];

void input() {
	cin >> r1 >> c1 >> r2 >> c2;
}

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		int dis = visited[yy][xx];
		q.pop();
		if (yy == r2 && xx == c2) {
			cout << dis - 1;
			return;
		}
		for (int i = 0; i < 8; i++) {
			int py = yy + dy[i];
			int px = xx + dx[i];
			bool chk = 0;  //상의 경로중에 왕이 있는지 체크
			if (py < 0 || py >= 10 || px < 0 || px >= 9)
				continue;
			if (visited[py][px])
				continue;

			int tempY = yy, tempX = xx;
			for (int j = 0; j < 2; j++) {
				if (tempY + v[i][j].first == r2 && tempX + v[i][j].second == c2) {
					chk = 1;  //경로 중에 왕이 있다.
					break;
				}
				tempY += v[i][j].first;
				tempX += v[i][j].second;
			}
			if (chk)
				continue;
			q.push({ py,px });
			visited[py][px] = dis + 1;
		}
	}
	cout << -1;
}

void solve() {
	// 상의 이동경로
	v[0] = { {0,1}, {-1,1} };
	v[1] = { {0,1}, {1,1} };
	v[2] = { {1,0},{1,1} };
	v[3] = { {1,0},{1,-1} };
	v[4] = { {0,-1},{1,-1} };
	v[5] = { {0,-1},{-1,-1} };
	v[6] = { {-1,0},{-1,-1} };
	v[7] = { {-1,0},{-1,1} };
	bfs(r1, c1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}