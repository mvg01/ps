#include <bits/stdc++.h>
using namespace std;

int n, m;
int mat[1001][1001];
int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>>q;
    q.push({ y,x });
    mat[y][x] = 1;
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ry = yy + d[i][0] + n;
            int rx = xx + d[i][1] + m;
            ry %= n;
            rx %= m;
            if (mat[ry][rx] == 0) {
                q.push({ ry,rx });
                mat[ry][rx] = 1;
            }
        }
    }
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}