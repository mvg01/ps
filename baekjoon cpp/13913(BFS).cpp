#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[200001], res[200001], p[200001];

void bfs(int start) {
	queue<int> q;
	visited[start] = 1;
	q.push(start);
	res[start] = 0;
	p[n] = -1;
	bool brk = 0;
	while (!q.empty()) {
		int a[3];
		a[0] = q.front() * 2;
		a[1] = q.front() + 1; 
		a[2] = q.front() - 1; 
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (a[i] == k) {
				if (i == 0) {
					p[a[i]] = a[i] / 2;
					res[a[i]] = res[a[i] / 2] + 1;
				}
				else if (i == 1) {
					p[a[i]] = a[i] - 1;
					res[a[i]] = res[a[i] - 1] + 1;
				}
				else if (i == 2) {
					p[a[i]] = a[i] + 1;
					res[a[i]] = res[a[i] + 1] + 1;
				}
				return;
			}
			if (visited[a[i]] == 0 && a[i] <= 100000 && a[i] >= 0) {
				q.push(a[i]);
				visited[a[i]] = 1;
				if (i == 0) {
					p[a[i]] = a[i] / 2;
					res[a[i]] = res[a[i] / 2] + 1;
				}
				else if (i == 1) {
					p[a[i]] = a[i] - 1;
					res[a[i]] = res[a[i] - 1] + 1;
				}
				else if (i == 2) {
					p[a[i]] = a[i] + 1;
					res[a[i]] = res[a[i] + 1] + 1;
				}
			}
		}
	}
}

void solve() {
	bfs(n);
	if (n == k) {
		cout << 0 << '\n' << k;
	}
	else {
		cout << res[k] << '\n';
		vector<int>v;
		v.push_back(k);
		while (1) {
			if (p[k] == -1) break;
			v.push_back(p[k]);
			k = p[k];
		}
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	}
}

void input() {
	cin >> n >> k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
}