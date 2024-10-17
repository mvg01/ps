#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
#define INF 99999999
using namespace std;

int m, n, res = INF;
int mat[101][101];
int dx[4] = { 1,-1,0,0 };  // 동,서,남,북
int dy[4] = { 0,0,1,-1 };
int visited[101][101][4];
int sy, sx, sd, ey, ex, ed;

void input() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    cin >> sy >> sx >> sd >> ey >> ex >> ed;
    sy--; sx--; sd--;  ey--; ex--; ed--;
}

void bfs() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++)
                visited[i][j][k] = INF;
        }
    }
    queue<tuple<int, int, int>>q;  // y,x,방향
    q.push({ sy,sx,sd });
    visited[sy][sx][sd] = 0;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int d = get<2>(q.front());
        int r = visited[y][x][d];
        q.pop();
        if (y == ey && x == ex && d == ed) {
            res = min(res, r);
        }
        for (int j = 0; j < 4; j++) {
            if (visited[y][x][j] > r + 1) { // 더 적은 명령으로 가능하다면
                q.push({ y, x, j });
                if (d == 0 && j == 1)
                    visited[y][x][j] = r + 2;
                else if (d == 1 && j == 0)
                    visited[y][x][j] = r + 2;
                else if (d == 2 && j == 3)
                    visited[y][x][j] = r + 2;
                else if (d == 3 && j == 2)
                    visited[y][x][j] = r + 2;
                else
                    visited[y][x][j] = r + 1;
            }
        }
        for (int i = 1; i <= 3; i++) {
            int yy = y + dy[d] * i;
            int xx = x + dx[d] * i;
            if (yy >= m || yy < 0 || xx >= n || xx < 0)
                break;
            if (mat[yy][xx] == 1)
                break;
            if (visited[yy][xx][d] < r + 1) // 탐색할 방향을 확인했을 때 더 적은 명령이면 push
                continue;
            q.push({ yy,xx,d });
            visited[yy][xx][d] = r + 1;
        }
    }
    cout << res;
}

void solve() {
    bfs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}

/*
5 6
0 0 0 0 0 0
0 1 1 0 1 0
0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
4 2 3
1 6 2
ans:8
*/