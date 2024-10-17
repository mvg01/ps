#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 9999999
using namespace std;

int r, c;
int sx, sy, ex, ey;  // 시작지점, 도착지점
char mat[51][51];
int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 }; 
int water[51][51];   // 물이 차는 시간 저장
int visited[51][51];
queue<pair<int, int>>wq;  // 물

void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> mat[i];
}

void bfs1() {  // 믈이 차오르는 시간
    while (!wq.empty()) {
        int y = wq.front().first;
        int x = wq.front().second;
        int t = water[y][x];
        wq.pop();
        for (int i = 0; i < 4; i++) {
            int yy = dy[i] + y;
            int xx = dx[i] + x;
            if (yy >= r || yy < 0 || xx >= c || xx < 0)
                continue;
            if (water[yy][xx] != INF)
                continue;
            if (mat[yy][xx] == '.') {
                water[yy][xx] = t + 1;
                wq.push({ yy,xx });
            }
        }
    }
}
void bfs2() {  // 고슴도치의 이동
    bool chk = 0;
    int res = 0;
    queue<pair<int, int>>q;
    q.push({ sy,sx });
    visited[sy][sx] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int t = visited[y][x];
        q.pop();
        if (y == ey && x == ex) {
            chk = 1;
            res = t - 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int yy = dy[i] + y;
            int xx = dx[i] + x;
            if (yy >= r || yy < 0 || xx >= c || xx < 0)
                continue;
            if (water[yy][xx] <= t + 1)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] == '.' || mat[yy][xx] == 'D') {
                q.push({ yy,xx });
                visited[yy][xx] = t + 1;
            }
        }
    }
    if (chk) 
        cout << res;
    else
        cout << "KAKTUS";
}

void solve() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == '*') {
                wq.push({ i,j });
                water[i][j] = 1;
            }
            else if (mat[i][j] == 'D') {
                ex = j;
                ey = i;
                water[i][j] = INF;
            }
            else if (mat[i][j] == 'S') {
                sx = j;
                sy = i;
            }
            else
                water[i][j] = INF;
            //물이 차는 시간이 INF면 고슴도치가 도달 가능한 영역
        }
    }
    bfs1();
    bfs2();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}