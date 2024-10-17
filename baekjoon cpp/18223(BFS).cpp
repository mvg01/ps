#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int dis[5001];
int n, e, p;
vector<pair<int, int> > v[5001];

void input() {
    cin >> n >> e >> p;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int w = v[ver][i].second;
            if (dis[next_ver] > dist + w) {
                dis[next_ver] = dist + w;
                pq.push({dist + w, next_ver});
            }
        }
    }
}

void solve() {
    dijkstra(1);
    int res = dis[n];  // 시작 지접에서 마산까지 
    int geon = dis[p];  // 시작 지점에서 건우까지
    dijkstra(p);
    int plus = dis[n];  // 건우 지점에서 마산까지
    if (geon + plus == res)
        cout << "SAVE HIM";
    else
        cout << "GOOD BYE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
