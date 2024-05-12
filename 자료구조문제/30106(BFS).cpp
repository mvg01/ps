#include <bits/stdc++.h>
using namespace std;

int n, m, k, res = 0;
int mat[501][501];
int visited[501][501];
int d[2][4] = { {1,0,0,-1},{0,1,-1,0} };
void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

void bfs(int y,int x) {
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    res++;
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = yy + d[0][i];
            int dx = xx + d[1][i];
            if (dy >= n || dy < 0 || dx >= m || dx < 0)
                continue;
            if (visited[dy][dx])
                continue;
            if (abs(mat[dy][dx] - mat[yy][xx]) <= k) {
                q.push({ dy,dx });
                visited[dy][dx] = 1;
            }
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) bfs(i, j);
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