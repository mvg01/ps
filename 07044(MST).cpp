#include <bits/stdc++.h>
using namespace std;

// 최소 신장트리 가중치를 최대로
int n, m, res = 0;
int parent[1001];
vector<pair<int, pair<int, int>>>v;

void init() {
	for (int i = 0; i <= n; i++)
		parent[i] = i;
}
int find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}
bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
bool com(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
	return a.second.second > b.second.second;
}

void kruskal() {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int first = v[i].first;
		int second = v[i].second.first;
		if (!sameparent(first, second)) {
			uni(first, second);
			res += v[i].second.second;
			cnt++;
			if (cnt == n - 1)
				break;
		}
	}
	if (cnt != n - 1)
		res = -1;
}

void input() {
	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,{b,c} });
	}
}

void solve() {
	sort(v.begin(), v.end(), com);  // 가중치 내림차순 정렬
	init();
	kruskal();
	cout << res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
}