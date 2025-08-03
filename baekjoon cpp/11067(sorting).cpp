#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y;
vector<int>xx[100001];
vector<pair<int, int>>ans;

void solve() {
    int idx = 0, pre = 0;
    for (int i = 0; i <= 100000; i++) {
        sort(xx[i].begin(), xx[i].end());
        int cur = 1e8;
        for (int j = 0; j < xx[i].size(); j++) {
            if (xx[i][j] == pre)
                cur = xx[i][j];
        }
        if (cur == 1e8)
            continue;
        if (cur == xx[i][0]) {
            for (int j = 0; j < xx[i].size(); j++) {
                ans.push_back({ i,xx[i][j] });
                pre = xx[i][j];
            }
        }
        else {
            for (int j = xx[i].size() - 1; j >= 0; j--) {
                ans.push_back({ i,xx[i][j] });
                pre = xx[i][j];
            }
        }
    }
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            xx[x].push_back(y);
        }
        solve();
        cin >> m;
        int d[11];
        for (int i = 0; i < m; i++) cin >> d[i];
        for (int i = 0; i < m; i++) cout << ans[d[i] - 1].first << ' ' << ans[d[i] - 1].second << '\n';
        ans.clear();
        for (int i = 0; i <= 100000; i++)
            xx[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}