#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, m, t, s, g, h;
int dis[2001][3];
vector<int>x;
vector<pair<int, int>>v[2001];

void dijkstra(int start, int idx) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });
    dis[start][idx] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int w = v[ver][i].second;
            if (dis[next_ver][idx] > dist + w) {
                dis[next_ver][idx] = dist + w;
                pq.push({ dist + w,next_ver });
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) 
            dis[i][j] = INF;  
    }
    dijkstra(s, 0);
    dijkstra(g, 1);
    dijkstra(h, 2);
    vector<int>res;
    for (int i = 0; i < t; i++) {
        // 목적지에 갈 수 없는 경우 제외
        if (dis[x[i]][0] == INF || dis[x[i]][1] == INF || dis[x[i]][2] == INF)
            continue;
        // 시작점에서 목적지까지의 합과 시작점에서 g까지 + g에서 h까지 + h에서 목적지까지 합이 같다면
        if ((dis[x[i]][0] == dis[g][0]+ dis[h][1] + dis[x[i]][2]) || (dis[x[i]][0] == dis[h][0] + dis[g][2] + dis[x[i]][1]))
            res.push_back(x[i]);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << '\n';
}

void input() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> t >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({ b,c });
            v[b].push_back({ a,c });
        }
        for (int i = 0; i < t; i++) {
            int a;
            cin >> a;
            x.push_back(a);
        }
        solve();
        x.clear();
        for (int i = 0; i <= n; i++) 
            v[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}