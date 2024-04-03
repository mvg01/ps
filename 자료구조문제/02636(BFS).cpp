#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int mat[101][101];
int visited[101][101];   // 매 시간마다 공기를 체크
int dy[4] = { 0,-1,1,0 };
int dx[4] = { 1,0,0,-1 };

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }  
}

void bfs_air() {
    queue<pair<int, int>>q; 
    q.push({ 0,0 });  // 공기의 시작은 0,0 부터
    visited[0][0] = 1;
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
            if (mat[yy][xx] == 0) {
                q.push({ yy,xx });
                visited[yy][xx] = 1;
            }
        }
    }
}

int cheese() {
    int cnt = 0;  // 현재 시간에 녹은 치즈
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (mat[i][j] == 1) {
                bool chk = 0;
                for (int d = 0; d < 4; d++) {
                    int yy = i + dy[d];
                    int xx = j + dx[d];
                    if (visited[yy][xx]) {  // 치즈가 녹을 것
                        mat[i][j] = 0;
                        chk = 1;
                        break;
                    }
                }
                if (chk)
                    cnt++;
            }
        }
    }
    return cnt;
}

bool clear() {
    bool chk = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
            if (mat[i][j] == 1)
                chk = 1;
        }
    }
    return chk;
}

void solve() {
    int cnt = 1, left = 0;
    while (1) {
        bfs_air();
        left = cheese();
        if (clear())
            cnt++;
        else
            break;
    }
    cout << cnt << '\n' << left;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}