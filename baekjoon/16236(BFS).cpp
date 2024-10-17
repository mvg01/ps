#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Fish {
	int size = 2;
	int f = 0;
}Fish;

Fish fish;
int n, res = 0;
int curY, curX, minY, minX, curDis;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int mat[21][21];
int visited[21][21];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 9) {
				curX = j;
				curY = i;
				mat[i][j] = 0;
			}
		}
	}
}

bool c(pair<int, int>a, pair<int, int>b) {
	if (a.first < b.first)
		return true;
	else if (a.first > b.first)
		return false;
	else {
		if (a.second < b.second)
			return true;
		else
			return false;
	}
}

int bfs(int y,int x) {
	int time = -1;
	bool min_chk = 0;
	queue<tuple<int, int, int>>q;
	vector<pair<int, int>>v;
	q.push({ y,x,0 });
	visited[y][x] = 1;
	while (!q.empty()) {
		int yy = get<0>(q.front());
		int xx = get<1>(q.front());
		int dis = get<2>(q.front());
		if (dis == time && mat[yy][xx] != 0) {
			if (mat[yy][xx] < fish.size)
				v.push_back({ yy,xx });
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ry = yy + dy[i];
			int rx = xx + dx[i];
			if (ry >= n || ry < 0 || rx >= n || rx < 0)
				continue;
			if (visited[ry][rx])
				continue;
			if (mat[ry][rx] == 0) {
				q.push({ ry,rx,dis + 1 });
				visited[ry][rx] = 1;
				continue;
			}
			if (mat[ry][rx] <= fish.size) {
				if (mat[ry][rx] < fish.size) {
					if (!min_chk)  // 가장 가까운 & 먹을 수 있는 물고기 거리
						time = dis + 1;
					min_chk = 1;
				}
				visited[ry][rx] = 1;
				q.push({ ry,rx,dis + 1 });
			}
		}
	}
	if (!v.empty()) {
		sort(v.begin(), v.end(), c);
		mat[v[0].first][v[0].second] = 0;  // 먹힌 물고기
		fish.f++;
		if (fish.size == fish.f) {
			fish.size++;
			fish.f = 0;
		}
		curY = v[0].first;
		curX = v[0].second;
	}
	return time;
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
	}
}

void solve() {
	while (1) {
		int t = bfs(curY, curX);
		if (t == -1)
			break;
		res += t;
		init();
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}