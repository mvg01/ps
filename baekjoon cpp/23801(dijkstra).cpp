#include <bits/stdc++.h>
#define INF 1e18
using namespace std;
using ll = long long;

int n, m, x, z, p;
ll a[100001], dis[100001][2];
vector<pair<int, ll>>mat[100001];

void dijkstra(int start, int idx) {
    for (int i = 0; i <= n; i++) dis[i][idx] = INF;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
    pq.push({ 0,start });
    dis[start][idx] = 0;
    while (pq.size()) {
        auto [d, ver] = pq.top();
        pq.pop();
        if (dis[ver][idx] < d)  // 경로 최적화
            continue;
        for (auto i : mat[ver]) {
            int nxt_ver = i.first;
            ll nxt_d = i.second;
            if (dis[nxt_ver][idx] > nxt_d + d) {
                dis[nxt_ver][idx] = nxt_d + d;
                pq.push({ nxt_d + d,nxt_ver });
            }
        }
    }
}

void solve() {
    dijkstra(x, 0);
    dijkstra(z, 1);
    ll ans = 1e18;
    for (int i = 0; i < p; i++) {
        if (dis[a[i]][0] == INF || dis[a[i]][1] == INF)
            continue;
        ans = min(ans, dis[a[i]][0] + dis[a[i]][1]);
    }
    if (ans == 1e18)
        cout << -1;
    else
        cout << ans;
}

void input() {
    int u, v;
    ll w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        mat[u].push_back({ v,w });
        mat[v].push_back({ u,w });
    }
    cin >> x >> z >> p;
    for (int i = 0; i < p; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}