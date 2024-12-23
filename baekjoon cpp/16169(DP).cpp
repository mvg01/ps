#include <bits/stdc++.h>
using namespace std;

int n, dp[101], idx;
vector<pair<int, int>>v[101];

void solve() {
    for (auto i : v[1]) dp[i.first] = i.second;
    for (int i = 1; i < idx; i++) {
        for (auto j : v[i]) {
            for (auto k : v[i + 1]) {
                dp[k.first] = max(dp[k.first], (j.first - k.first) * (j.first - k.first) + dp[j.first] + k.second);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        ans = max(ans, dp[i]);
    cout << ans;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({ i,b });
        idx = max(idx, a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}