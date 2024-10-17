#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, m, x, y, a, b, c, res = 1;
int dis[1001];
vector<pair<int, int>>v[1001];

void input() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
}

void solve() { 
    for (int i = 0; i < n; i++) dis[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,y });
    dis[y] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int w = v[ver][i].second;
            if (dis[next_ver] > dist + w) {
                dis[next_ver] = dist + w;
                pq.push({ dist + w,next_ver });
            }
        }
    }
    sort(dis, dis + n);
    int temp = x;
    for (int i = 0; i < n; i++) {
        if (dis[i] * 2 > x) {
            cout << -1;
            return;
        }
        if (temp - dis[i] * 2 >= 0) 
            temp -= dis[i] * 2;
        else {
            temp = x;
            res++;
            i--;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}