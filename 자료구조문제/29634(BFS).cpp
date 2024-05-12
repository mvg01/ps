#include <bits/stdc++.h>
using namespace std;

int n, m, res = -1;
char mat[31][31];
int visited[31][31];
int d[2][4] = { {1,0,0,-1},{0,1,-1,0} };
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> mat[i];
}

void bfs(int y,int x) {
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    int cnt = 1;
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
            if (mat[dy][dx]=='.') {
                q.push({ dy,dx });
                visited[dy][dx] = 1;
                cnt++;
            }
        }
    }
    res = max(res, cnt);
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.' && !visited[i][j]) bfs(i, j);
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