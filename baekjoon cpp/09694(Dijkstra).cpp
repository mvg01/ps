#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int t, n, m;
int dis[21], pre[21];
vector<pair<int, int>>v[21];

void init() {
    for (int i = 0; i < 21; i++) {
        dis[i] = INF;
        pre[i] = -1;
        v[i].clear();
    }
}

void solve(int q) {
    priority_queue<pair<int, int>>pq;
    pq.push({ 0,0 });
    dis[0] = 0;
    while (pq.size()) {
        auto [w, ver] = pq.top();
        pq.pop();
        w *= -1;
        for (int i = 0; i < v[ver].size(); i++) {
            int n_ver = v[ver][i].first;
            int n_w = v[ver][i].second;
            if (dis[n_ver] > w + n_w) {
                dis[n_ver] = w + n_w;
                pre[n_ver] = ver;
                pq.push({ -dis[n_ver],n_ver });
            }
        }
    }
    vector<int> ans;
    // 경로 역추적
    for (int cur = m - 1; cur != -1; cur = pre[cur]) 
        ans.push_back(cur);
    reverse(ans.begin(), ans.end());

    cout << "Case #" << q << ": ";
    if (ans.size() == 1)
        cout << -1;
    else
        for (auto i : ans) cout << i << ' ';
    cout << '\n';
}   

void input() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        init();
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({ b,c });
            v[b].push_back({ a,c });
        }
        solve(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}