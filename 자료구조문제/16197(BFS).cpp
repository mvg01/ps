#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[21][21];
queue<tuple<int, pair<int, int>, pair<int, int>>>q;
vector<pair<int, int>>v;
bool visited[21][21][21][21];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'o') {
                v.push_back({ i,j });
                mat[i][j] = '.';
            }
        }
    }
}

void solve() {
    q.push({ 0, { v[0].first,v[0].second }, { v[1].first,v[1].second } });
    visited[v[0].first][v[0].second][v[1].first][v[1].second] = 1;
    while (!q.empty()) {
        int cnt = get<0>(q.front());
        pair<int, int>p1 = get<1>(q.front());
        pair<int, int>p2 = get<2>(q.front());
        q.pop();
        if (cnt >= 10)
            continue;

        for (int i = 0; i < 4; i++) {
            int y1 = p1.first + d[i][0];
            int x1 = p1.second + d[i][1];
            int y2 = p2.first + d[i][0];
            int x2 = p2.second + d[i][1];
            if (mat[y1][x1] == '#') {
                y1 -= d[i][0];
                x1 -= d[i][1];
            }
            if (mat[y2][x2] == '#') {
                y2 -= d[i][0];
                x2 -= d[i][1];
            }
            
            bool chk = 0;  // 나간 동전 확인
            if (y1 >= n || y1 < 0 || x1 >= m || x1 < 0)
                chk = 1;
            if (y2 >= n || y2 < 0 || x2 >= m || x2 < 0) {
                if (chk)
                    continue;
                else {
                    cout << cnt + 1;
                    return;
                }
            }
            if (chk) {
                cout << cnt + 1;
                return;
            }

            if (visited[y1][x1][y2][x2])
                continue;

            q.push({ cnt + 1,{y1,x1},{y2,x2} });
            visited[y1][x1][y2][x2] = 1;
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}