#include <bits/stdc++.h>
using namespace std;

int n, m, sy, sx;
int dis[4][2][2][51][51];  // 방향, 첫번째 C, 두번째 C, y, x
int d[4][2] = { {0,1},{1,0},{0,-1},{-1,0 } };
char mat[51][51];
vector<pair<int, int>>c;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'C')
                c.push_back({ i,j });
            else if (mat[i][j] == 'S') {
                sy = i;
                sx = j;
            }
        }
    }
    queue<tuple<int, int, int, int, bool, bool>>q;
    q.push({ -1,0,sy,sx,0,0 });
    while (!q.empty()) {
        int dir = get<0>(q.front());
        int t = get<1>(q.front());
        int y = get<2>(q.front());
        int x = get<3>(q.front());
        bool chk1 = get<4>(q.front());  // 첫 번째 C 방문여부
        bool chk2 = get<5>(q.front());  // 두 번째 C 방문여부
        q.pop();
        if (chk1 && chk2) {
            cout << t;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            bool c1 = chk1;
            bool c2 = chk2;
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (dir == i || mat[yy][xx] == '#')
                continue;
            if (!dis[i][c1][c2][yy][xx]) {
                if (yy == c[0].first && xx == c[0].second)
                    c1 = 1;
                else if (yy == c[1].first && xx == c[1].second)
                    c2 = 1;
                q.push({ i,t + 1,yy,xx,c1,c2 });
                dis[i][c1][c2][yy][xx] = 1;
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