#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, s, e, le = 1e9, ri = 0, ans = 0;
vector<pair<int, int>>v[100001];
bool vis[100001];

bool bfs(int p) {
    for (int i = 0; i < 100001; i++) vis[i] = 0;
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
        int ver = q.front();
        q.pop();
        if (ver == e)
            return 1;
        for (int i = 0; i < v[ver].size(); i++) {
            if (v[ver][i].second >= p && !vis[v[ver][i].first]) {
                vis[v[ver][i].first] = 1;
                q.push(v[ver][i].first);
            }
        }
    }
    return 0;
}

void solve() {
    while (le <= ri) {
        int mid = (le + ri) / 2;
        if (bfs(mid)) {
            le = mid + 1;
            ans = max(ans, mid);
        }
        else
            ri = mid - 1;
    }
    cout << ans;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
        le = min(le, c);
        ri = max(ri, c);
    }
    cin >> s >> e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}