#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey;
char mat[201][201];
bool vis[201][201][5], tim[201][201][4];
int d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
queue<pair<int, int>>g;  // 유령 좌표

void solve() {
    while (g.size()) {   // 유령이 보는 시간대를 tim 배열로 체크
        int y = g.front().first;
        int x = g.front().second;
        int f = mat[y][x] - '0';
        g.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y, xx = x;
            int dir = (f + i + 1) % 4; // ex) 시간이 0이라면 1초때는 못간다 의미
            while (1) {
                yy += d[dir][0];
                xx += d[dir][1];
                if (yy >= n || yy < 0 || xx >= m || xx < 0)
                    break;
                if (mat[yy][xx] != '.')
                    break;
                tim[yy][xx][i] = 1;
            }
        }
    }
    queue<tuple<int, int, int>>q;
    q.push({ sy,sx,0 });
    vis[sy][sx][0] = 1;
    while (q.size()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        if (y == ey && x == ex) {
            cout << t;
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (mat[yy][xx] != '.')
                continue;
            if (tim[yy][xx][t % 4]) {  // 유령의 시야에 있음
                if (vis[y][x][(t + 1) % 4])  // 한 곳에 최대 4번까지 머무를 수 있음
                    continue;
                if (tim[y][x][t % 4])  // 이곳엔 머무를 수 조차 없음
                    continue;
                q.push({ y,x,t + 1});
                vis[y][x][(t + 1) % 4] = 1;
            }
            else {  // 유령의 시야에 없으니 통과
                if (vis[yy][xx][(t + 1) % 4])
                    continue;
                q.push({ yy,xx,t + 1 });
                vis[yy][xx][(t + 1) % 4] = 1;
            }
        }
    }
    cout << "GG";
}

void input() {
    cin >> n >> m >> sy >> sx >> ey >> ex;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] >= '0' && mat[i][j] <= '3')
                g.push({ i,j });
        }
    }
    sy--; sx--; ey--; ex--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}