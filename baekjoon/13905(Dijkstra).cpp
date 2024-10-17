#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999999999
using namespace std;

int n, m, s, e;
vector<pair<int, int>>v[100001];
int dis[100001];  // 시작 정점에서부터 가질 수 있는 최대 빼빼로

void solve() {
    priority_queue<pair<int, int>>pq;  // 가중치 내림차순 그냥 사용
    pq.push({ INF,s });
    dis[s] = INF;
    while (!pq.empty()) {
        int weight = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        if (dis[ver] > weight)
            continue;
        for (int i = 0; i < v[ver].size(); i++) {
            int next_weight = min(weight, v[ver][i].second);
            int next_ver = v[ver][i].first;
            if (dis[next_ver] < next_weight) {
                dis[next_ver] = next_weight;
                pq.push({ next_weight,next_ver });
            }
        }
    }
    cout << dis[e];
}

void input() {
    cin >> n >> m >> s >> e;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}