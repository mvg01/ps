#include <iostream>
#include <queue>
#include <vector>
#define INF 999999999
using namespace std;

int t, c, ts, te;
int dis[2501];
vector<pair<int, int>>v[2501];

void input() {
    int a, b, z;
    cin >> t >> c >> ts >> te;
    for (int i = 0; i < c; i++) {
        cin >> a >> b >> z;
        v[a].push_back({ b,z });  // 양방향 연결
        v[b].push_back({ a,z });
    }
}

void solve() {
    for (int i = 1; i <= t; i++)
        dis[i] = INF;
    priority_queue<pair<int, int>>pq;
    dis[ts] = 0;
    pq.push({ 0,ts });
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int p = v[ver][i].second;
            if (dis[next_ver] > dist + p) {
                dis[next_ver] = dist + p;
                pq.push({ -dis[next_ver],next_ver });
            }
        }
    }
    cout << dis[te];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}