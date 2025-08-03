#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, k, a, b, t, c[201];
int dis[201][201];

void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << dis[i][j] << ' ';
        cout << '\n';
    }
    */
    vector<int>ans;
    int mn = INF;
    for (int i = 1; i <= n; i++) {
        int mx = -1, d = 0;
        for (auto j : c) {  // 준형이와 친구들의 도시에서 가장 먼 도시의 왕복거리 찾기
            if (dis[i][j] != INF && dis[j][i] != INF) 
                mx = max(mx, dis[i][j] + dis[j][i]);  
            else break;
        }
        // cout << mx << ' ';
        // 그 가장 먼 도시중에서 최소 거리의 도시
        if (mn > mx) {
            mn = mx;
            ans.clear();
            ans.push_back(i);
        }
        else if (mn == mx)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
}

void input() {
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) 
            if (i != j) dis[i][j] = INF;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        dis[a][b] = min(dis[a][b], t);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> c[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}