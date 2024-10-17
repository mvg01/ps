#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, res = 10000;
char mat[51][51];
int visited[51][51];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

int bfs(int y, int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
    }
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        int dis = visited[yy][xx];
        q.pop();
        if (dis > res)  // 메모리 초과 방지 -> 쓸데 없는 곳 탐지 안함
            break;
        for (int i = 0; i < 4; i++) {
            int ry = yy + dy[i];
            int rx = xx + dx[i];
            if (ry < 0 || ry >= n || rx < 0 || rx >= m)
                continue;
            if (visited[ry][rx])
                continue;
            if (mat[ry][rx] == '.') {
                q.push({ ry,rx });
                visited[ry][rx] = dis + 1;
            }
            else if (mat[ry][rx] == 'X')
                return dis - 1;
        }
    }
    return 10000;
}

void dfs(int y, int x) {  // 두 구간 중 하나 구간 1로 만들기
    mat[y][x] = '1';
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        if (mat[yy][xx] == 'X' && !visited[yy][xx])
            dfs(yy, xx);
    }
}

void solve() {
    bool brk = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'X') {
                dfs(i, j);
                brk = 1;
                break;
            }
        }
        if (brk)
            break;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '1')
                res = min(res, bfs(i, j));
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}