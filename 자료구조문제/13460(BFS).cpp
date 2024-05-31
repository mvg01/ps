#include <bits/stdc++.h>
using namespace std;

int n, m, rx, ry, bx, by;
char mat[11][11];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };   // 우 상 하 좌
bool v[11][11][11][11];
queue<tuple<int, int, int, int, int>>q;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

void solve() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'R') {
                mat[i][j] = '.';
                rx = j;
                ry = i;
            }
            if (mat[i][j] == 'B') {
                mat[i][j] = '.';
                bx = j;
                by = i;
            }
        }
    }
    q.push({ ry,rx,by,bx,1 });
    v[ry][rx][by][bx] = 1;
    while (!q.empty()) {
        int y1 = get<0>(q.front());
        int x1 = get<1>(q.front());
        int y2 = get<2>(q.front());
        int x2 = get<3>(q.front());
        int cnt = get<4>(q.front());
        q.pop();
        if (cnt == 11)
            continue;
        for (int i = 0; i < 4; i++) {
            int dy1 = y1;
            int dx1 = x1;
            int dy2 = y2;
            int dx2 = x2;
            bool end = 0;
            bool chk = 0;  // 빨간 구슬만 통과
            bool chk1 = 0, chk2 = 0;  // 구슬들이 더 이상 움직일 수 없는지
            if (y1 == y2 && i == 0) {
                if (x1 < x2) {
                    while (1) {
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == '#') {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;  // 파란 구슬이 먼저 들어감
                            break;
                        }
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                            break;
                        }
                        if (mat[dy1][dx1] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
                else {
                    while (1) {
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == '#') {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                        }
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;
                            break;
                        }
                        if (mat[dy2][dx2] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
            }
            else if (y1 == y2 && i == 3) {
                if (x1 > x2) {
                    while (1) {
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == '#') {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;  // 파란 구슬이 먼저 들어감
                            break;
                        }
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                            break;
                        }
                        if (mat[dy1][dx1] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
                else {
                    while (1) {
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == '#') {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                        }
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;
                            break;
                        }
                        if (mat[dy2][dx2] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
            }
            else if (x1 == x2 && i == 1) {
                if (y1 < y2) {
                    while (1) {
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == '#') {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;  // 파란 구슬이 먼저 들어감
                            break;
                        }
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                            break;
                        }
                        if (mat[dy1][dx1] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
                else {
                    while (1) {
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == '#') {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                        }
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;
                            break;
                        }
                        if (mat[dy2][dx2] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
            }
            else if (x1 == x2 && i == 2) {
                if (y1 > y2) {
                    while (1) {
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == '#') {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;  // 파란 구슬이 먼저 들어감
                            break;
                        }
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                            break;
                        }
                        if (mat[dy1][dx1] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
                else {
                    while (1) {
                        dy1 += d[i][0];
                        dx1 += d[i][1];
                        if (mat[dy1][dx1] == '#') {
                            dy1 -= d[i][0];
                            dx1 -= d[i][1];
                            chk1 = 1;
                        }
                        if (mat[dy1][dx1] == 'O') {
                            chk = 1;
                        }
                        dy2 += d[i][0];
                        dx2 += d[i][1];
                        if (mat[dy2][dx2] == 'O') {
                            end = 1;
                            break;
                        }
                        if (mat[dy2][dx2] == '#' || (dy1 == dy2 && dx1 == dx2)) {
                            dy2 -= d[i][0];
                            dx2 -= d[i][1];
                            chk2 = 1;
                        }
                        if (chk1 && chk2)  // 두 구슬 다 이동 불가
                            break;
                    }
                }
            }
            else {
                while (1) {
                    dy1 += d[i][0];
                    dx1 += d[i][1];
                    if (mat[dy1][dx1] == '#') {
                        dy1 -= d[i][0];
                        dx1 -= d[i][1];
                        chk1 = 1;
                    }
                    if (mat[dy1][dx1] == 'O') {
                        chk = 1;
                        break;
                    }
                    dy2 += d[i][0];
                    dx2 += d[i][1];
                    if (mat[dy2][dx2] == '#') {
                        dy2 -= d[i][0];
                        dx2 -= d[i][1];
                        chk2 = 1;
                    }
                    if (mat[dy2][dx2] == 'O') {
                        end = 1;
                        break;
                    }
                    if (chk1 && chk2)  // 두 구슬 다 이동 불가
                        break;
                }
            }
            if (chk && !end) {
                cout << cnt;
                return;
            }
            if (end)
                continue;
            if (!v[dy1][dx1][dy2][dx2]) {
                v[dy1][dx1][dy2][dx2] = 1;
                q.push({ dy1,dx1,dy2,dx2,cnt + 1 });
            }
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