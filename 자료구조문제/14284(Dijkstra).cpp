#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int n, m, s, t;
vector<pair<int, int>>mat[5001];
int dis[5001];
void input() {
    int a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mat[a].push_back({ b,c });
        mat[b].push_back({ a,c });
    }
    cin >> s >> t;
}

void dijkstra() {
    priority_queue<pair<int, int>>pq;
    dis[s] = 0;
    pq.push({ 0,s });
    while (!pq.empty()) {
        int w = -pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        for (int i = 0; i < mat[vertex].size(); i++) {
            int v = mat[vertex][i].first;
            int plus = mat[vertex][i].second;
            if (dis[v] > w + plus) {
                dis[v] = w + plus;
                pq.push({ -dis[v],v });
            }
        }
    }
}

void solve() {
    for (int i = 0; i <= n; i++)
        dis[i] = INF;
    dijkstra();
    cout << dis[t];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}