#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>>v[1001];
priority_queue<int>dis[1001];  // max-heap, 최단거리들 저장, top 에는 k번째 최단거리가 저장되도록 큐의 사이즈를 k개 이하로 제한

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
}

void solve() {
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // min-heap 
    dis[1].push(0);
    pq.push({ 0,1 });
    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int w = v[ver][i].second;
            if (dis[next_ver].size() < k) {
                dis[next_ver].push(dist + w);
                pq.push({ dist + w,next_ver });
            }
            else {
                if (dist + w < dis[next_ver].top()) {
                    dis[next_ver].pop();
                    dis[next_ver].push(dist + w);
                    pq.push({ dist + w,next_ver });
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i].size() < k)
            cout << -1 << '\n';
        else 
            cout << dis[i].top() << '\n';  
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
