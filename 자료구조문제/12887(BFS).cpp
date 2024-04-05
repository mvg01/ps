#include <iostream>
#include <queue>
using namespace std;

int m;
char mat[2][51];
int visited[2][51];
int dy[4] = { 0,-1,1,0 };
int dx[4] = { 1,0,0,-1 };
void input() {
    cin >> m;
    for (int i = 0; i < 2; i++)
        cin >> mat[i];
}
int bfs(int s) {
    if (mat[s][0] == '#')  // 시작할 수 없는 경우
        return 100;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < m; j++) visited[i][j] = 0;
    queue<pair<int, int>>q;
    q.push({ s,0 });
    visited[s][0] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (x == m - 1)
            return visited[y][x];
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy >= 2 || yy < 0 || xx >= m || xx < 0)
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
void solve() {
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++)
            if (mat[i][j] == '.') cnt++;
    }
    int x = min(bfs(0), bfs(1));  // 두번의 시작 중에서 최소 경로
    cout << cnt - x;  // . 개수에서 최소 경로를 빼준 값이 정답
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}