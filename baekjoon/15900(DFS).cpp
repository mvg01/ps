#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int>v[500001];
int dis[500001] = { 0 };
bool visited[500001];
void input() {
	int x, y;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

void dfs(int node, int cnt) {
	if (node != 1 && v[node].size() == 1) {
		dis[node] += cnt;
		return;
	}
	int size = v[node].size();
	for (int j = 0; j < size; j++) {
		if (!visited[v[node][j]]) {
			visited[v[node][j]] = 1;
			dfs(v[node][j], cnt + 1);
		}
	}
}

void solve() {  
	int cnt = 0;
	visited[1] = 1;
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cnt += dis[i];
	}
	if (cnt % 2)
		cout << "Yes";
	else
		cout << "No";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}