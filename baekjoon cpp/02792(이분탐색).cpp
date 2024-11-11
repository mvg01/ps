#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, ans;
ll a[300001];

void solve() {
	// mid는 1명에게 최대로 줄 수 있는 사탕 수 (그 이상은 못준다고 가정)
	ll start = 1, end = a[m - 1], mid;
	while (start <= end) {
		mid = (start + end) / 2;
		ll cnt = 0;
		for (int i = 0; i < m; i++) {
			if (a[i] >= mid)
				cnt += a[i] / mid;
			if (a[i] % mid != 0)
				cnt++;
		}
		if (cnt > n) {
			start = mid + 1;
		}
		else {
			ans = mid;
			end = mid - 1;
		}
	}
	cout << ans;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
		cin >> a[i];
	sort(a, a + m);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
}