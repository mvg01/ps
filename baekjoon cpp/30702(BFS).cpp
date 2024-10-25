#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[51][51], mat2[51][51];
int vis[51][51];
int d[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };

bool bfs(int y, int x) {
    vis[y][x] = 1;
    queue<pair<int, int>>q;
    q.push({ y,x });
    char a = mat[y][x], b = mat2[y][x];
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ry = yy + d[i][0];
            int rx = xx + d[i][1];
            if (ry < 0 || ry >= n || rx < 0 || rx >= m)
                continue;
            if (vis[ry][rx])
                continue;
            if (mat[ry][rx] == a) {
                if (mat2[ry][rx] == b) {
                    q.push({ ry,rx });
                    vis[ry][rx] = 1;
                }
                else 
                    return 1;
            }
        }
    }
    return 0;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                bool chk = bfs(i, j);
                if (chk) {
                    cout << "NO";
                    return;
                }
            }
        }
    }
    cout << "YES";
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    for (int i = 0; i < n; i++)
        cin >> mat2[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}