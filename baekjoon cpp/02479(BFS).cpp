#include <bits/stdc++.h>
using namespace std;

int n, k, s, e;
string c[1001];
vector<int>v[1001];
bool vis[1001];
int parent[1001];  // 정점 역추적 위한 배열

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dis = 0;
            for (int z = 0; z < k; z++) {
                if (c[i][z] != c[j][z])
                    dis++;
            }
            if (dis == 1) {  // 해밍 경로 연결
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
        int ver = q.front();
        if (ver == e) {
            vector<int>res;
            res.push_back(e);
            while (e != s) {  // 경로 역추적
                e = parent[e];
                res.push_back(e);
            }
            for (int i = res.size() - 1; i >= 0; i--) 
                cout << res[i] + 1 << ' ';
            return;
        }
        q.pop();
        for (int next : v[ver]) {
            if (!vis[next]) {
                vis[next] = 1;
                parent[next] = ver;
                q.push(next);
            }
        }
    }
    cout << -1;
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> s >> e;
    s--; e--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}