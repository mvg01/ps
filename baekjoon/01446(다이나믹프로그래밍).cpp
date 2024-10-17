#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, d;
vector<pair<int, int>>v[10001];
int dp[10001];

void input() {
	int a, b, c;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
}

void solve() {
	for (int i = 0; i <= d; i++) 
		dp[i] = i;

	for (int i = 0; i <= d; i++) {
		if (i != 0)
			dp[i] = min(dp[i], dp[i - 1] + 1);

		if (v[i].size() > 0) {
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j].first <= d && v[i][j].first - v[i][j].second >= i) {
					dp[v[i][j].first] = min(dp[v[i][j].first], dp[i] + v[i][j].second);
				}
			}
		}
	}
	cout << dp[d];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}