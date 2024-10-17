#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, m;
bool visited[200001];
vector<int>v[200001];
long long res = 1;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int bfs(int b) {
    queue<int>q;
    q.push(b);
    visited[b] = 1;
    int c = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int y = v[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = 1;
                c++;
            }
        }
    }
    return c;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            res *= bfs(i);
            res %= MOD;
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