#include <bits/stdc++.h>
using namespace std;

int n, c[200001], ans = 0;
vector<int>v[200001];
bool vis[200001];

void dfs(int p, int color) {
    if (c[p] != color) {
        ans++;
        for (auto i : v[p]) {
            if (!vis[i]) {
                vis[i] = 1;
                dfs(i, c[p]);
            }
        }
    }
    else {
        for (auto i:v[p]) {
            if (!vis[i]) {
                vis[i] = 1;
                dfs(i, color);
            }
        }
    }
}

void solve() {
    vis[1] = 1;
    if (c[1] != 0) ans++;  // 루트가 흰색이 아니라면
    dfs(1, c[1]);
    cout << ans;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0; i < n - 1; i++) {
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