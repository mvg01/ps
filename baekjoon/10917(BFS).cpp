#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, m;
int visited[100001];
vector<int>v[100001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        visited[i] = INF;
}

void bfs() {
    queue<int>q;
    q.push(1);
    visited[1] = 0;
    while (!q.empty()) {
        int y = q.front();
        int dis = visited[y];
        q.pop();
        if (y == n) {
            cout << dis;
            return;
        }
        for (int i = 0; i < v[y].size(); i++) {
            int x = v[y][i];
            if (visited[x] > dis + 1) {
                visited[x] = dis + 1;
                q.push(x);
            }
        }   
    }
    cout << -1;
}

void solve() {
    bfs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}