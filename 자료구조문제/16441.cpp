#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[101][101];
int visited[101][101];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int> > v;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'W') v.push_back({i, j});
    }
}

void solve() {
    queue<tuple<int, int, int> > q;
    for (int i = 0; i < v.size(); i++) {
        q.push({v[i].first, v[i].second, -1});
        visited[v[i].first][v[i].second] = 1;
    }
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dir = get<2>(q.front());
        q.pop();
        if (dir == -1) {
            for (int i = 0; i < 4; i++) {
                int yy = y + d[i][0];
                int xx = x + d[i][1];
                if (yy >= n || yy < 0 || xx >= m || xx < 0)
                    continue;
                if (visited[yy][xx])
                    continue;
                if (mat[yy][xx] == '.') {
                    q.push({yy, xx, -1});
                    visited[yy][xx] = 1;
                }
                if (mat[yy][xx] == '+') {
                    q.push({yy, xx, i}); // i 방향으로 미끄러짐
                }
            }
        } else {  // 현재 얼음
            int i = dir;
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] == '.') {
                q.push({yy, xx, -1});
                visited[yy][xx] = 1;
            }
            if (mat[yy][xx] == '+') {
                q.push({yy, xx, i});
            }
            if (mat[yy][xx] == '#') {
                q.push({y, x, -1});
                visited[y][x] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.' && !visited[i][j])
                mat[i][j] = 'P';
            cout << mat[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}