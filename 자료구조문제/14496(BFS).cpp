#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int a, b, n, m;
vector<int>mat[1001];
int dis[1001] = { 0 };

void input() {
	int x, y;
	cin >> a >> b >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--;
		y--;
		mat[x].push_back(y);
		mat[y].push_back(x);
	}
	a--; b--;
}

void bfs() {
	queue<int>q;
	q.push(a);
	dis[a] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == b)
			break;

		int size = mat[x].size();
		for (int i = 0; i < size; i++) {
			if (!dis[mat[x][i]]) {
				dis[mat[x][i]] = dis[x] + 1;
				q.push(mat[x][i]);
			}
		}
	}
}

void solve() {
	bfs();
	cout << dis[b] - 1;  //dis의 시작값이 1이라서
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}