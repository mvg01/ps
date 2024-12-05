#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<int>v[26];
int vis[26][26];

void init() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++)
            vis[i][j] = 0;
    }
}

void dfs(int ver, int dis) {
    for (int i = 0; i < v[ver].size(); i++) {
        int next = v[ver][i];
        if (vis[ver][next] || vis[next][ver])
            continue;
        vis[ver][next]++;
        vis[next][ver]++;
        ans = max(ans, dis + 1);
        dfs(next, dis + 1);
        vis[ver][next]--;
        vis[next][ver]--;
    }
}

void input() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 0; i < n; i++) {
            init();
            dfs(i, 0);
        }
        cout << ans << '\n';
        ans = 0;
        for (int i = 0; i < 26; i++) v[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}