#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int mat[301][301];
int visited[301][301];
int ry, rx;
int res = 0;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		if (yy == ry && xx == rx)
			res = min(res, visited[ry][rx]);
		q.pop();
		for (int i = 0; i < 8; i++) {
			int cy = yy + dy[i];
			int cx = xx + dx[i];
			if (cy >= n || cy < 0 || cx >= n || cx < 0)
				continue;
			if (visited[cy][cx])
				continue;
			q.push({ cy,cx });
			visited[cy][cx] = visited[yy][xx] + 1;
		}
	}
}

void init() {
	res = 1000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}


int main()
{
	int t, y, x;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> y >> x;
		cin >> ry >> rx;
		init();
		bfs(y, x);
		cout << res << '\n';
	}
}