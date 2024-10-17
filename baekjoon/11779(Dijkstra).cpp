#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, m, s, e;
int dis[1001];
int chk[1001];
vector<pair<int, int>>v[1001];


void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
    cin >> s >> e;
}

void solve() {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({ 0,s });
    dis[s] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        if (dis[ver] < dist)  // 방문했던 정점인데 더 최적화 시킬 수 없는 경우 배제
            continue;
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int w = v[ver][i].second;
            if (dis[next_ver] > dist + w) {
                dis[next_ver] = dist + w;
                chk[next_ver] = ver;
                pq.push({ dist + w,next_ver });
            }
        }
    }
    vector<int>res;
    int t = e;
    res.push_back(t);
    while (1) {
        res.push_back(chk[t]);
        t = chk[t];
        if (t == s)
            break;
    }
    cout << dis[e] << '\n' << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
