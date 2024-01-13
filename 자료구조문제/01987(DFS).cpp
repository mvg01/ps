#include <iostream>
#include <vector>
using namespace std;

int r, c, res = 1;
vector<string>v;
bool visited[26];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void input() {
	string s;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		v.push_back(s);
	}
}

void dfs(int y, int x, int dis) {
	res = max(res, dis);

	for (int i = 0; i < 4; i++) {
		res = max(res, dis + 1);
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy >= r || yy < 0 || xx >= c || xx < 0)
			continue;
		if (visited[v[yy][xx]-'A'])
			continue;
		visited[v[yy][xx] - 'A'] = true;
		dfs(yy, xx, dis + 1);
		visited[v[yy][xx] - 'A'] = false;
	}
}

void solve() {
	visited[v[0][0] - 'A'] = true;
	dfs(0, 0, 0);
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}