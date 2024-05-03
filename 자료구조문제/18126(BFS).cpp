#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n;
ll res = 0;
vector<pair<int, ll>>v[5001];
bool visited[5001];

void input() {
    int a, b;
    ll c;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
}

void bfs() {
    queue<pair<int, ll>>q;
    visited[1] = 1;
    for (int i = 0; i < v[1].size(); i++) {
        q.push({ v[1][i].first,v[1][i].second });
        visited[v[1][i].first] = 1;
    }
    while (!q.empty()) {
        int ver = q.front().first;
        ll dis = q.front().second;
        q.pop();
        res = max(res, dis);
        for (int i = 0; i < v[ver].size(); i++) {
            int nx = v[ver][i].first;
            if (!visited[nx]) {
                q.push({ nx,v[ver][i].second + dis });
                visited[nx] = 1;
            }
        }
    }
}

void solve() {
    bfs();
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}