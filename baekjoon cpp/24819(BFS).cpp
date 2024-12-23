#include <bits/stdc++.h>
using namespace std;

int t, n, m;
char mat[101][101];
bool vis[101][101];
int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
pair<int, int>s;

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ s.first,s.second,0 });
    vis[s.first][s.second] = 1;
    while (q.size()) {
        auto [y, x, tm] = q.front();
        // cout << y << ' ' << x << "\n";
        q.pop();
        if (t < tm) {
            continue;
        }
        if (y == n - 1 || y == 0 || x == m - 1 || x == 0) {
            cout << tm;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0) continue;
            if (vis[yy][xx]) continue;
            if (mat[yy][xx] == 'U' && i == 0) {
                q.push({ yy,xx,tm + 1 });
                vis[yy][xx] = 1;
            }
            if (mat[yy][xx] == 'D' && i == 1) {
                q.push({ yy,xx,tm + 1 });
                vis[yy][xx] = 1;
            }
            if (mat[yy][xx] == 'R' && i == 3) {
                q.push({ yy,xx,tm + 1 });
                vis[yy][xx] = 1;
            }
            if (mat[yy][xx] == 'L' && i == 2) {
                q.push({ yy,xx,tm + 1 });
                vis[yy][xx] = 1;
            }
            if (mat[yy][xx] == '0') {
                q.push({ yy,xx,tm + 1 });
                vis[yy][xx] = 1;
            }
        }
    }
    cout << "NOT POSSIBLE";
}

void input() {
    cin >> t >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'S')
                s = { i, j };
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}