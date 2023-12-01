#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int>v[10001];
int visited[10001];
int cnt[10001] = { 0 };

void input() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		//v[a].push_back(b);
		v[b].push_back(a);
	}
}

void init() {
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
}

int bfs(int start) {
	int cn = 1;
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int p = q.front();
		int len = v[p].size();
		q.pop();
		for (int i = 0; i < len; i++) {
			if (!visited[v[p][i]]) {
				q.push(v[p][i]);
				visited[v[p][i]] = 1;
				cn++;
			}
		}
	}
	return cn;
}

void solve() {
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		init();
		cnt[i] = bfs(i);
		if (cnt[i] >= mx)
			mx = cnt[i];
	}
	for (int i = 1; i <= n; i++) {
		if (mx == cnt[i])
			cout << i << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}