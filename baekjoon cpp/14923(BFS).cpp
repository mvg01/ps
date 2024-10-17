#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, res = 1000000;
int sx, sy, ex, ey;   // 시작좌표, 끝좌표
int mat[1001][1001];
int visited[1001][1001][2];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
queue<tuple<int, int, bool>>q;

void input() {
    cin >> n >> m >> sy >> sx >> ey >> ex;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    }
}

void bfs() {
    q.push({ sy,sx, 0 });  //0은 벽을 아직 뚫지 않았음을 의미
    visited[sy][sx][0] = 1;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        bool brk = get<2>(q.front());
        int dis = visited[y][x][brk];
        q.pop();
        if (y == ey && x == ex) {
            res = dis - 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy > n || yy <= 0 || xx > m || xx <= 0)  //좌표 밖 범위
                continue;
            if (brk == 0 && mat[yy][xx] == 1) {  //아직 벽을 부시지 않았으면
                q.push({ yy,xx,1 });
                visited[yy][xx][1] = dis + 1;
            }
            else if (mat[yy][xx] == 0 && visited[yy][xx][brk] == 0) {
                q.push({ yy,xx,brk });
                visited[yy][xx][brk] = dis + 1;
            }
        }
    }
    if (res != 1000000)
        cout << res;
    else
        cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs();
}
