#include <iostream>
#include <queue>
using namespace std;

int t, h, w, cur = 1, res = 0;
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,1,-1,0 };
char mat[1001][1001];
int visited[1001][1001];

void input() {
    cin >> h >> w >> t;
    for (int i = 0; i < h; i++) 
        cin >> mat[i];
}

void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            visited[i][j] = 0;
    }
}

void bfs(int y, int x, int mx) {
    int time = 0;
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    while (!q.empty()) {
        int ry = q.front().first;
        int rx = q.front().second;
        q.pop();
        if (mat[ry][rx] == mx + '0') {
            res += visited[ry][rx] - 1;
            init();
            bfs(ry, rx, mx + 1);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int yy = ry + dy[i];
            int xx = rx + dx[i];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] == '.' || mat[yy][xx] != 'X') {
                q.push({ yy,xx });
                visited[yy][xx] = visited[ry][rx] + 1;
                time++;
                if (mat[yy][xx] != '.')
                    cur++;
            }
        }
    }
}

void solve() {
    int s_i = 0, s_j = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mat[i][j] == 'S') {
                s_i = i;
                s_j = j;
            }
        }
    }
    bfs(s_i, s_j, 1);
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}