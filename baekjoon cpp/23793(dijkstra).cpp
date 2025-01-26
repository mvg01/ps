#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, x, y, z, x_y, x_z, y_z;
int dis[100001];
vector<pair<int, int>>mat[100001];

void dijkstra(int start) {
    for (int i = 0; i <= 100000; i++) dis[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({ 0,start });
    dis[start] = 0;
    while (pq.size()) {
        int d = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < mat[ver].size(); i++) {
            int nxt_ver = mat[ver][i].first;
            int nxt_d = mat[ver][i].second;
            if (nxt_ver == y && dis[nxt_ver] > nxt_d + d) {  // y를 거치는 정점은 거리만 기록
                dis[nxt_ver] = nxt_d + d;
                continue;
            }
            if (dis[nxt_ver] > nxt_d + d) {
                dis[nxt_ver] = nxt_d + d;
                pq.push({ nxt_d + d,nxt_ver });
            }
        }
    }
}

void solve() {
    // dijkstra 3번 돌리면 시간초과임 ㅋㅋ
    dijkstra(x);
    x_y = dis[y];
    x_z = dis[z];
    dijkstra(y);
    y_z = dis[z];
    if (x_y == INF || y_z == INF)
        cout << -1 << ' ';
    else
        cout << x_y + y_z << ' ';
    if (x_z == INF)
        cout << -1;
    else
        cout << x_z;
}

void input() {
    int u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        mat[u].push_back({ v,w });
    }
    cin >> x >> y >> z;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}