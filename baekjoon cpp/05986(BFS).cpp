#include <bits/stdc++.h>
using namespace std;

int n, res = 0;
char mat[101][101][101];
int visited[101][101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[3] = { 0,-1,1 };
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
}

void bfs(int z,int y,int x) {
    queue<tuple<int, int, int>>q;
    q.push({ z,y,x });
    visited[z][y][x] = 1;
    while (!q.empty()) {
        int zz = get<0>(q.front());
        int yy = get<1>(q.front());
        int xx = get<2>(q.front());
        q.pop();
        for (int k = 0; k < 3; k++) {
            int rz = zz + dz[k];
            if (rz >= n || rz < 0)
                continue;
            if (k == 0) {
                for (int i = 0; i < 4; i++) {
                    int ry = yy + dy[i];
                    int rx = xx + dx[i];
                    if (ry >= n || ry < 0 || rx >= n || rx < 0)
                        continue;
                    if (visited[rz][ry][rx])
                        continue;
                    if (mat[rz][ry][rx] == '*') {
                        q.push({ rz,ry,rx });
                        visited[rz][ry][rx] = 1;
                    }
                }
            }
            else {
                if (visited[rz][yy][xx])
                    continue;
                if (mat[rz][yy][xx] == '*') {
                    q.push({ rz,yy,xx });
                    visited[rz][yy][xx] = 1;
                }
            }
        }
    }
    res++;
}

void solve() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[k][i][j] == '*' && !visited[k][i][j])
                    bfs(k, i, j);
            }
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