#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, l, r;
bool visited[100001];
void input() {
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++)
            visited[j] = 1;
    }
}

void solve() {
    queue<pair<int, int>>q;
    if (!visited[a])
        q.push({ a,1 });
    if (!visited[b])
        q.push({ b,1 });
    while (!q.empty()) {
        int v = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (v == n) {
            cout << cnt;
            return;
        }
        if (a + v <= n) {
            if (!visited[a + v]) {
                q.push({ a + v,cnt + 1 });
                visited[a + v] = 1;
            }
        }
        if (b + v <= n) {
            if (!visited[b + v]) {
                q.push({ b + v,cnt + 1 });
                visited[b + v] = 1;
            }
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}