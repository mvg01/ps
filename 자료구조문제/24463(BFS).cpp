#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, end_x, end_y;
char mat[2002][2002];
int visited[2002][2002];
int visited2[2002][2002];
int dy[4] = { 0,-1,1,0 };
int dx[4] = { 1,0,0,-1 };
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}
void bfs(int sy, int sx) {
    queue<pair<int, int>>q;
    q.push({ sy,sx });
    visited[sy][sx] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] == '.') {
                q.push({ yy,xx });
                visited[yy][xx] = visited[y][x] + 1;
            }
        }
    }
}
void bfs2(int sy, int sx) {  // 도착 지점에서 시작해서 방문 거리(visited)가 다르면 @
    queue<tuple<int, int, int>>q;
    q.push({ sy,sx,visited[sy][sx] });
    visited2[sy][sx] = 1;
    mat[sy][sx] = '*';  // 실제 최단 경로
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dis = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (visited2[yy][xx])
                continue;
            if (mat[yy][xx] == '.') {
                if (visited[yy][xx] == dis - 1) {
                    mat[yy][xx] = '*';  // 실제 최단 경로
                    q.push({ yy,xx,dis - 1 });
                    visited2[yy][xx] = 1;
                }
                else {
                    mat[yy][xx] = '@';
                    q.push({ yy,xx,dis });
                    visited2[yy][xx] = 1;
                }
            }
        }
    }
}

void solve() {
    int cnt = 0, start_x = 0, start_y = 0;
    bool chk = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                cnt++;
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) { 
                    if (!chk) {
                        start_y = i;
                        start_x = j;
                        chk = 1;
                    }
                    else {
                        end_y = i;
                        end_x = j;
                    }
                }
            }
        }
    }
    bfs(start_y, start_x);
    bfs2(end_y, end_x);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '*')
                cout << '.';
            else if (mat[i][j] == '+')
                cout << '+';
            else  // 사용하지 않은 '.' 칸 모두 ex) 예제4의 (9,9)
                cout << '@';
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