#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, t, ans;
int dis[301][301];

void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
        }
    }
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << dis[a][b] << '\n';
    }
}

void input() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                dis[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = c;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}