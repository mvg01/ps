#include <bits/stdc++.h>
using namespace std;

int n, m, p, k, b[100001], ans[100001], af[1001];
vector<int>v[100001];
bool vis[100001];

void solve() {
    af[0] = k;
    for (int i = 1; i < 1001; i++) {
        af[i] = af[i - 1] + (i + 1) * k;
        if (af[i] > 1000000)
            break;
    }
    queue<tuple<int, int, int>>q;
    for (int i = 0; i < p; i++) {
        q.push({ b[i],0,0 });
        ans[b[i]] = 0;
        vis[b[i]] = 1;
    }
    while (q.size()) {
        auto [y, c, kk] = q.front();
        q.pop();
        for (int i = 0; i < v[y].size(); i++) {
            if (!vis[v[y][i]]) {
                if (c + 1 == af[kk]) 
                    q.push({ v[y][i],c + 1,kk + 1 });
                else 
                    q.push({ v[y][i],c + 1,kk });
                vis[v[y][i]] = 1;
                ans[v[y][i]] = kk + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

void input() {
    cin >> n >> m >> p >> k;
    for (int i = 0; i < p; i++) cin >> b[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}