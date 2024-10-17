#include <bits/stdc++.h>
using namespace std;

int n, m, res = 0;
int mat[101][101];
int visited[101][101];
int d[2][4] = { {1,-1,0,0},{0,0,-1,1} };

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
    }
}

void refresh() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2)
                mat[i][j] = 0;
        }
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ry = yy + d[0][i];
            int rx = xx + d[1][i];
            if (ry >= n || ry < 0 || rx >= m || rx < 0) 
                continue;
            if (visited[ry][rx])
                continue;
            if (mat[ry][rx] == 0) {
                q.push({ ry,rx });
                visited[ry][rx] = 1;
            }
        }
    }
}

void solve() {
    while (1) {
        init();
        bool chk = 0;
        // 1. 가장자리 공기가 외부와 유입된 공기인지 bfs 방문배열로 체크
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                for (int j = 0; j < m; j++) {
                    if (!visited[i][j])
                        bfs(i, j);
                }
            }
            else {
                if (!visited[i][0])
                    bfs(i, 0);
                if (!visited[i][m - 1])
                    bfs(i, m - 1);
            }
        }
        // 2. 치즈가 외부 공기와 2개 이상 인접한지 체크
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    chk = 1;
                    int cnt = 0;
                    for (int a = 0; a < 4; a++) {
                        int ry = i + d[0][a];
                        int rx = j + d[1][a];
                        if (visited[ry][rx])
                            cnt++;
                    }
                    if (cnt >= 2)
                        mat[i][j] = 2;
                }
            }
        }
        refresh();
        if (!chk)
            break;
        res++;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}