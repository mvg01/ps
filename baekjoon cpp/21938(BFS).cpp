#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

vector<tuple<int, int, int>>v[1001];
int mat[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int n, m;

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] < 0 || yy + dy[i] >= n || xx + dx[i] < 0 || xx + dx[i] >= m)
				continue;
			if (visited[yy + dy[i]][xx + dx[i]])
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] == 1) {
				q.push({ yy + dy[i],xx + dx[i] });
				visited[yy + dy[i]][xx + dx[i]] = 1;
			}
		}
	}
}

int main()
{
	int t, cnt = 0;
	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a >> b >> c;
			v[i].push_back({ a,b,c });
		}
	}
	cin >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = get<0>(v[i][j]) + get<1>(v[i][j]) + get<2>(v[i][j]);
			sum = double(sum);
			double avr = sum / 3;
			if (avr >= t)
				mat[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 && !visited[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}