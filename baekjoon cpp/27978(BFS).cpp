#include <bits/stdc++.h>
using namespace std;

int h, w, sy, sx, ry, rx;
char mat[501][501];
bool vis1[501][501];  // 물살 방문여부
bool vis2[501][501];  // 연료 써서 방문여부
int d1[3][2] = { {-1,1},{0,1},{1,1} };  // 물살
int d2[5][2] = { {-1,-1},{-1,0},{0,-1},{1,-1},{1,0} };

void solve() {
    deque<tuple<int, int, int>>d;
    d.push_front({ sy,sx,0 }); 
    vis1[sy][sx] = 1;
    vis2[sy][sx] = 1; // 출발지로 돌아갈 일 없음
    while (d.size()) {
        int y = get<0>(d.front());
        int x = get<1>(d.front());
        int dis = get<2>(d.front());
        if (ry == y && rx == x) {
            cout << dis;
            return;
        }
        d.pop_front();
        for (int i = 0; i < 3; i++) {  // 물살
            int yy = y + d1[i][0];
            int xx = x + d1[i][1];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (vis1[yy][xx])
                continue;
            if (mat[yy][xx] == '*') {
                d.push_front({ yy,xx,dis });
            }
            else if (mat[yy][xx] != '#') {
                d.push_front({ yy,xx,dis });
                vis1[yy][xx] = 1;
            }
        }
        for (int i = 0; i < 5; i++) {  // 연료
            int yy = y + d2[i][0];
            int xx = x + d2[i][1];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (vis1[yy][xx] || vis2[yy][xx])
                continue;
            if (mat[yy][xx] == '*') {
                d.push_back({ yy,xx,dis + 1 });
            }
            else if (mat[yy][xx] != '#') {
                d.push_back({ yy,xx,dis + 1 });
                vis2[yy][xx] = 1;
            }
        }
    }
    cout << -1;
}

void input() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> mat[i];
        for (int j = 0; j < w; j++) {
            if (mat[i][j] == 'K') {
                sy = i;
                sx = j;
            }
            if (mat[i][j] == '*') {
                ry = i;
                rx = j;
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