#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int d[6][2] = { {-1,1},{0,1},{1,1},{1,0},{0,-1},{-1,0} };
int f[6][2] = { {-1,0},{0,1},{1,0},{1,-1},{0,-1},{-1,-1} };
bool vis[1001][1001];

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ 0,0,0 });
    vis[0][0] = 1;
    while (q.size()) {
        auto [y, x, c] = q.front();
        q.pop();
        if (y == n - 1 && x == m - 1) {
            cout << c;
            return;
        }
        for (int i = 0; i < 6; i++) {
            int yy, xx;
            if (y % 2) {
                yy = y + d[i][0];
                xx = x + d[i][1];
            }
            else {
                yy = y + f[i][0];
                xx = x + f[i][1];
            }
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis[yy][xx])
                continue;
            q.push({ yy,xx,c + 1 });
            vis[yy][xx] = 1;
        }
    }
    cout << -1;
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        vis[y][x] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}