#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, t, m, l;
int vis[10001], dis[10001];
vector<tuple<int, int, int>>mat[10001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

void solve() {
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    pq.push({ 0,0,1 });
    vis[1] = 0;
    dis[1] = 0;
    while (pq.size()) {
        int d = get<0>(pq.top());
        int tim = get<1>(pq.top());
        int ver = get<2>(pq.top());
        pq.pop();
        for (auto i : mat[ver]) {
            int nxt = get<0>(i);
            int nxt_t = get<1>(i);
            int nxt_d = get<2>(i);
            if (d + nxt_d > m)
                continue;
            if (tim + nxt_t > t)
                continue;
            // 시간 대비 거리 효율도 체크
            int temp = (d + nxt_d) / (tim + nxt_t);
            if (dis[nxt] > d + nxt_d || vis[nxt] < temp) {
                dis[nxt] = min(dis[nxt], d + nxt_d);
                vis[nxt] = temp;
                pq.push({ d + nxt_d,tim + nxt_t,nxt });
            }
        }
    }
    if (dis[n] != INF)
        cout << dis[n];
    else
        cout << -1;
}

void input() {
    cin >> n >> t >> m >> l;
    for (int i = 0; i < l; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mat[a].push_back({ b,c,d });
        mat[b].push_back({ a,c,d });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}