#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[1001][1001];
int vis[1001][1001];
int d[4][2] = { {0,1},{-1,0},{1,0},{0,-1} };

bool check(int y, int x, char c) {
    int yy = 0, xx = 0;
    for (int i = y; i < n; i++) {
        if (mat[i][x] == c)
            yy++;
        else
            break;
    }
    for (int i = x; i < m; i++) {
        if (mat[y][i] == c)
            xx++;
        else
            break;
    }
    int cnt = 1;
    queue<pair<int, int>>q;
    q.push({ y,x });
    vis[y][x] = 1;
    while (q.size()) {
        auto [yy, xx] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
            if (vis[dy][dx])
                continue;
            if (mat[dy][dx] == c) {
                q.push({ dy,dx });
                vis[dy][dx] = 1;
                cnt++;
            }
        }
    }
    if (cnt == yy * xx)
        return 0;
    else
        return 1;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                if (check(i, j, mat[i][j])) {
                    cout << "BaboBabo";
                    return;
                }
            }
        }
    }
    cout << "dd";
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}