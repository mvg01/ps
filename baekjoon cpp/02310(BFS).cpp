#include <bits/stdc++.h>
using namespace std;

int n, p[1001], vis[1001];
char t[1001];
vector<int>v[1001];

void solve() {
    bool chk = 0;
    queue<pair<int, int>>q;
    q.push({ 1,0 });
    vis[1] = 0;
    while (q.size()) {
        int r = q.front().first;
        int m = q.front().second;
        q.pop();
        if (r == n) {
            if (t[r] == 'T') {
                if (m >= p[r]) {
                    chk = 1;
                    break;
                }
            }
            else {
                chk = 1;
                break;
            }
        }
        for (int i = 0; i < v[r].size(); i++) {
            if (t[r] == 'E') {
                if (vis[v[r][i]] < m) {
                    vis[v[r][i]] = m;
                    q.push({ v[r][i],m });
                }
            }
            else if (t[r] == 'L') {
                if (vis[v[r][i]] < max(m, p[r])) {
                    vis[v[r][i]] = max(m, p[r]);
                    q.push({ v[r][i],vis[v[r][i]] });
                }
            }
            else if (t[r] == 'T') {
                if (m >= p[v[r][i]] && vis[v[r][i]] < m - p[v[r][i]]) {
                    vis[v[r][i]] = m - p[v[r][i]];
                    q.push({ v[r][i],vis[v[r][i]] });
                }
            }
        }
    }
    cout << ((chk) ? "Yes\n" : "No\n");
}

void input() {
    while (1) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < 1001; i++) {
            vis[i] = -1;
            v[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c >> p[i];
            t[i] = c;
            while (1) {
                int x;
                cin >> x;
                if (x == 0)
                    break;
                v[i].push_back(x);
            }
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}