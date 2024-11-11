#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, x;
ll cur = 0;
int a[500001], b[500001];

void solve() {
	for (int i = 0; i < n; i++) {
		cur += b[i];
		if (cur < a[i]) {
			cout << -1;
			return;
		}
	}
	cout << (cur - a[n - 1]) / x;
}

void input() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
}