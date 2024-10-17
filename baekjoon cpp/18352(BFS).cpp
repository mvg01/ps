#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, x;
vector<int>v[300001];
vector<int>res;
int visited[300001] = { 0 };
bool chk = 0;

void input() {
	cin >> n >> m >> k >> x;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
}

void bfs() {
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		int cur = q.front();
		int size = v[cur].size();
		q.pop();
		if (visited[cur] == k) {
			res.push_back(cur);
			continue;
		}

		for (int i = 0; i < size; i++) {
			if (visited[v[cur][i]] == 0 && v[cur][i] != x) {
				q.push(v[cur][i]);
				visited[v[cur][i]] = visited[cur] + 1;
			}
		}
	}
}

void solve() {
	bfs();
	sort(res.begin(), res.end());
	if (res.size() == 0)
		cout << -1;
	else {
		int size = res.size();
		for (int i = 0; i < size; i++)
			cout << res[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}