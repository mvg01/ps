#include <bits/stdc++.h>
using namespace std;

int n, m, z, f;
int mat[101][101];
int visited[101][101];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    cin >> z;
}

void solve() {
    f = mat[0][0];
    queue<pair<int, int>>q;
    q.push({ 0,0 });
    visited[0][0] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        if (y == n - 1 && x == m - 1) {
            cout << "ALIVE";
            return;
        }
        q.pop();
        for (int i = -z; i <= z; i++) {
            for (int j = -z; j <= z; j++) {
                int yy = y + i;
                int xx = x + j;
                if (abs(yy - y) + abs(xx - x) > z)
                    continue;
                if (yy >= n || yy < 0 || xx >= m || xx < 0)
                    continue;
                if (visited[yy][xx])
                    continue;
                if (mat[yy][xx] == f) {
                    q.push({ yy,xx });
                    visited[yy][xx] = 1;
                }
            }
        }
    }
    cout << "DEAD";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}