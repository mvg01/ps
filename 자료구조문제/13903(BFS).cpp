#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, n;
int mat[1001][1001];
int visited[1001][1001];
vector<pair<int, int>>v;

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> mat[i][j];
	}
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
}
void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			visited[i][j] = 0;
		}
	}
}

void bfs() {
	queue<pair<int, int>>q;
	for (int i = 0; i < c; i++) {
		if (mat[0][i] == 1) {
			q.push({ 0,i });
			visited[0][i] = 1;
		}
	}
	int min_dis = 100000000;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second; 
		int dis = visited[yy][xx];
		q.pop();
		if (yy == r - 1) {
			min_dis = min(min_dis, dis - 1);
			continue;
		}
		for (int i = 0; i < n; i++) {
			int dy = yy + v[i].first;
			int dx = xx + v[i].second;
			if (dy < 0 || dy >= r || dx < 0 || dx >= c)
				continue;
			if (visited[dy][dx])
				continue;
			if (mat[dy][dx] == 1) {
				q.push({ dy,dx });
				visited[dy][dx] = dis + 1;
			}
		}
	}
	if (min_dis != 100000000)
		cout << min_dis;
	else
		cout << -1;
}

void solve() {
	init();
	bfs();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}