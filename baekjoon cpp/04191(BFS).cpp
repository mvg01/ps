#include <bits/stdc++.h>
using namespace std;

int t, n, m, l, a, b;
vector<int>s;
vector<int>v[10001];
bool vis[10001];

void solve() {
    queue<int>q;
    for (auto i : s) {
        q.push(i);
        vis[i] = 1;
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto i : v[x]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) 
        if (vis[i]) ans++;
    cout << ans << '\n';
}

void init() {
    s.clear();
    for (int i = 0; i < 10001; i++) {
        v[i].clear();
        vis[i] = 0;
    }
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> l;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
        }
        for (int i = 0; i < l; i++) {
            cin >> a;
            s.push_back(a);
        }
        solve();
        init();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}