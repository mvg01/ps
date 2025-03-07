#include <bits/stdc++.h>
using namespace std;

int n, m, k, sy, sx;
int mat[2001][2001];
int dis[2001][2001];
bool vis1[2001][2001];
bool vis2[2001][2001];
queue<tuple<int, int, int>>q;
int d[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

void solve() {
    while (q.size()) {  // 마네킹과의 거리 구해두기 (O(N^2))
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dd = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis1[yy][xx])
                continue;
            vis1[yy][xx] = 1;
            dis[yy][xx] = dd + 1;
            q.push({ yy,xx,dd + 1 });
        }
    }
    q.push({ sy,sx,0 });
    vis2[sy][sx] = 1;
    while (q.size()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int c = get<2>(q.front());
        if (mat[y][x] == 2) {
            cout << c;
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis2[yy][xx])
                continue;
            if (mat[yy][xx] == 1)
                continue;
            if (dis[yy][xx] > k) {
                vis2[yy][xx] = 1;
                q.push({ yy,xx,c + 1 });
            }
        }
    }
    cout << -1;
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            dis[i][j] = 9990;
            if (mat[i][j] == 4) {
                sy = i;
                sx = j;
            }
            if (mat[i][j] == 3) {
                q.push({ i,j,0 });
                vis1[i][j] = 1;
                dis[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}