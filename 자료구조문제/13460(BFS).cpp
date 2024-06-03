#include <bits/stdc++.h>
using namespace std;

int n, m, rx, ry, bx, by;
char mat[11][11];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };   // 우 하 상 좌
bool v[11][11][11][11];
queue<tuple<int, int, int, int, int>> q;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

pair<int, int> move_ball(int y, int x, int dy, int dx) {
    while (mat[y + dy][x + dx] != '#' && mat[y][x] != 'O') {
        y += dy;
        x += dx;
    }
    return { y, x };
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'R') {
                mat[i][j] = '.';
                ry = i;
                rx = j;
            }
            if (mat[i][j] == 'B') {
                mat[i][j] = '.';
                by = i;
                bx = j;
            }
        }
    }

    q.push({ ry, rx, by, bx, 1 });
    v[ry][rx][by][bx] = true;

    while (!q.empty()) {
        int y1 = get<0>(q.front());
        int x1 = get<1>(q.front());
        int y2 = get<2>(q.front());
        int x2 = get<3>(q.front());
        int cnt = get<4>(q.front());
        q.pop();
        if (cnt == 11) continue;

        for (int i = 0; i < 4; i++) {
            int dy = d[i][0], dx = d[i][1];
            pair<int, int>m1, m2;
            m1 = move_ball(y1, x1, dy, dx);
            m2 = move_ball(y2, x2, dy, dx);
            int m1y = m1.first;
            int m1x = m1.second;
            int m2y = m2.first;
            int m2x = m2.second;
            if (mat[m1y][m1x] == 'O') {
                if (mat[m2y][m2x] != 'O') {
                    cout << cnt << '\n';
                    return;
                }
                else
                    continue;
            }
            if (mat[m2y][m2x] == 'O')
                continue;

            if (m1y == m2y && m1x == m2x) {
                if (abs(m1y - y1) + abs(m1x - x1) > abs(m2y - y2) + abs(m2x - x2)) {
                    m1y -= dy;
                    m1x -= dx;
                }
                else {
                    m2y -= dy;
                    m2x -= dx;
                }
            }
            if (!v[m1y][m1x][m2y][m2x]) {
                v[m1y][m1x][m2y][m2x] = 1;
                q.push({ m1y,m1x,m2y,m2x, cnt + 1 });
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}