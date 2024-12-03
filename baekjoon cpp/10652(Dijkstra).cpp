#include <bits/stdc++.h>
#define INF 1e18
using ll = long long;
using namespace std;

int b, e, p, n, m;
vector<int>mat[40001];
ll dis[40001][3];

void init() {
    for (int i = 1; i <= n; i++) {
        dis[i][0] = INF;
        dis[i][1] = INF;
        dis[i][2] = INF;
    }
}

void dijkstra(int s, int w, int idx) {
    priority_queue<pair<ll, int>>pq;
    dis[s][idx] = 0;
    pq.push({ 0,s });
    while (!pq.empty()) {
        ll dist = -pq.top().first;
        int ver = pq.top().second;
        pq.pop();

        for (int i = 0; i < mat[ver].size(); i++) {
            int next_ver = mat[ver][i];
            if (dis[next_ver][idx] > dist + w) {
                dis[next_ver][idx] = dist + w;
                pq.push({ -dis[next_ver][idx],next_ver });
            }
        }
    }
}

void solve() {
    init();
    dijkstra(1, b, 0);  // 베시
    dijkstra(2, e, 1);  // 엘시
    dijkstra(n, p, 2);  // 도착지에서 모든 정점
    ll ans = dis[n][0] + dis[n][1];
    for (int i = 1; i <= n; i++) { 
        if (dis[i][0] == INF || dis[i][1] == INF || dis[i][2] == INF)
            continue;
        ll sum = dis[i][0] + dis[i][1];
        ans = min(ans, sum + dis[i][2]);
    }
    cout << ans;
}

void input() {
    cin >> b >> e >> p >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        mat[s].push_back(t);
        mat[t].push_back(s);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
