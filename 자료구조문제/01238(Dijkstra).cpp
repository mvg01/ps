#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, m, x, res = 0;
int dis[1001][2];
vector<pair<int, int>>mat[1001][2];
void input() {
    int a, b, c;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mat[a][0].push_back({ b,c });
        mat[b][1].push_back({ a,c });
    }
}

void dijkstra(int r) {
    for (int i = 1; i <= n; i++)
        dis[i][r] = INF;
    priority_queue<pair<int, int>>pq;
    dis[x][r] = 0;
    pq.push({ 0,x });
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (auto i : mat[ver][r]) {
            int next_ver = i.first;
            int next_dis = i.second;
            if (dis[next_ver][r] > dist + next_dis) {
                dis[next_ver][r] = dist + next_dis;
                pq.push({ -dis[next_ver][r],next_ver });
            }
        }
    }
}

void solve() {
    dijkstra(0);  // X에서 집으로
    dijkstra(1);  // 반대로 추적
    for (int i = 1; i <= n; i++) 
        res = max(res, dis[i][0] + dis[i][1]);
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}