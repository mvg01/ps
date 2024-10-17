#include <bits/stdc++.h>
using namespace std;

int n, m;
int r1 = 1, r2 = 1, r3 = 0;
int mat[1001][1001];
int visited[1001][1001][2];
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<pair<int, int>>v[2];
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
                v[0].push_back({i,j});
            if (mat[i][j] == 2)
                v[1].push_back({i,j});
            if (mat[i][j] == -1) {
                visited[i][j][0] = 99999;
                visited[i][j][1] = 99999;
            }
        }
    }
}

void bfs() {
    queue<tuple<int, int, int>>q;
    q.push({ v[0][0].first,v[0][0].second, 0 });
    visited[v[0][0].first][v[0][0].second][0] = 1;
    q.push({ v[1][0].first,v[1][0].second, 1 });
    visited[v[1][0].first][v[1][0].second][1] = 1;

    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int s = get<2>(q.front());
        int dis = visited[y][x][s];
        q.pop();
        if (mat[y][x] == -1)  // 현재 지역이 3이 된 경우
            continue;
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (visited[yy][xx][s])
                continue;
            if (mat[yy][xx] != -1) {
                int chk = s ? 0 : 1;
                if (visited[yy][xx][chk] == dis+1) {
                    r3++;
                    mat[yy][xx] = -1;
                    if (s == 1)  // 3번 바이러스가 되면서 체크한 1 or 2 제거
                        r1--;
                    else
                        r2--;
                    continue;
                }
                if (visited[yy][xx][chk])
                    continue;
                q.push({ yy,xx,s });
                visited[yy][xx][s] = dis + 1;
                if (s == 0)
                    r1++;
                if (s == 1)
                    r2++;
            }
        }
    }
}

void solve() {
    bfs();
    cout << r1 << ' ' << r2 << ' ' << r3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}