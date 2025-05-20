#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, p;
int dis[2001][2001];
vector<int>mat[2001];

void solve() {
    queue<pair<int, int>>q;
    for (int i = 1; i <= n; i++) {
        q.push({ i,0 });
        while (q.size()) {
            int nxt = q.front().first;
            int w = q.front().second;
            q.pop();
            for (int k : mat[nxt]) {
                if (dis[i][k] > w + 1) {
                    dis[i][k] = w + 1;
                    q.push({ k,w + 1 });
                }
            }
        }
    }
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        int ans = INF;
        for (int j = 1; j <= n; j++) {
            if (dis[j][u] == INF || dis[j][v] == INF) 
                continue;
            int temp = max(dis[j][u], dis[j][v]);
            ans = min(ans, temp);
        }
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
}

void input() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                dis[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u].push_back(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}