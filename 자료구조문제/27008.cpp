#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int f, p, c, m;
int dis[501];
vector<pair<int, int>>v[501];
vector<int>res;

void input() {
    cin >> f >> p >> c >> m;
    for (int i = 0; i < p; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        v[q].push_back({ w,e });
        v[w].push_back({ q,e });
    }
}

bool dijkstra(int s) {
    for (int i = 1; i <= f; i++)
        dis[i] = INF;
    priority_queue<pair<int, int>>pq;
    dis[s] = 0;
    pq.push({ 0,s });
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_vertex = v[ver][i].first;
            int next_dis = v[ver][i].second;
            if (dis[next_vertex] > distance + next_dis) {
                dis[next_vertex] = distance + next_dis;
                pq.push({ -dis[next_vertex],next_vertex });
            }
        }
    }
    if (dis[1] <= m)
        return 1;
    return 0;
}

void solve() {
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        if (dijkstra(x))
            res.push_back(i + 1);
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}