#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, a, b, k, sy, sx, ey, ex;
int mat[501][501];
bool visited[501][501];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

void input() {
    int c, d;
    cin >> n >> m >> a >> b >> k;
    for (int i = 0; i < k; i++) {
        cin >> c >> d;
        mat[c - 1][d - 1] = 1;
    }
    cin >> sy >> sx >> ey >> ex;
    sy--; sx--; ey--; ex--;
}

bool chk_move(int y, int x, int d) {
    if (d == 0) {
        for (int i = x; i < x + b; i++) {
            if (mat[y + a][i] == 1)
                return true;
        }
    }
    if (d == 1) {
        for (int i = y; i < y + a; i++) {
            if (mat[i][x + b] == 1)
                return true;
        }
    }
    if (d == 2) {
        for (int i = y; i < y + a; i++) {
            if (mat[i][x - 1] == 1)
                return true;
        }
    }
    if (d == 3) {
        for (int i = x; i < x + b; i++) {
            if (mat[y - 1][i] == 1)
                return true;
        }
    }
    return false;
}

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ sy,sx,0 });
    visited[sy][sx] = 1;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();
        if (y == ey && x == ex) {
            cout << cnt;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy < 0 || xx < 0 || yy + a > n || xx + b > m)
                continue;
            if (visited[yy][xx])
                continue;
            bool chk = chk_move(y, x, i);
            if (chk)
                continue;
            q.push({ yy,xx,cnt + 1 });
            visited[yy][xx] = 1;
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