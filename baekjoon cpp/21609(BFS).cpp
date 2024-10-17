#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, mat[21][21], res = 0;
int visited[21][21];
int visited2[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
}

void init() {  // 무지개 블록 재 방문
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0)
                visited[i][j] = 0;
        }
    }
}

pair<int, int> bfs(int y, int x) {  // 색 별로 개수 찾기
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    int color = mat[y][x], cnt = 1, r_cnt = 0;
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ry = yy + dy[i];
            int rx = xx + dx[i];
            if (ry >= n || ry < 0 || rx >= n || rx < 0)
                continue;
            if (visited[ry][rx])
                continue;
            if (mat[ry][rx] == color || mat[ry][rx] == 0) {
                q.push({ ry,rx });
                visited[ry][rx] = 1;
                if (mat[ry][rx] == 0)
                    r_cnt++;
                else
                    cnt++;
            }
        }
    }
    return { cnt,r_cnt };
}

void bfs2(int y, int x) {  // 그룹 블록 제거 -> 제거된 블록을 -2로 표시한다
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited2[y][x] = 1;
    int color = mat[y][x];
    mat[y][x] = -2;
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ry = yy + dy[i];
            int rx = xx + dx[i];
            if (ry >= n || ry < 0 || rx >= n || rx < 0)
                continue;
            if (visited2[ry][rx])
                continue;
            if (mat[ry][rx] == color || mat[ry][rx] == 0) {
                q.push({ ry,rx });
                visited2[ry][rx] = 1;
                mat[ry][rx] = -2;
            }
        }
    }
}

void gravity() {  // 중력 함수
    int mat2[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            mat2[i][j] = mat[i][j];
    }
    for (int i = n-2; i >=0; i--) {
        for (int j = 0; j < n; j++) {
            if (mat2[i][j] >= 0) {
                int a;
                bool chk = 0;
                for (a = i + 1; a < n; a++) {
                    if (mat2[a][j] != -2) 
                        break;
                    chk = 1;
                }
                if (chk) {
                    mat2[a - 1][j] = mat2[i][j];
                    mat2[i][j] = -2;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            mat[i][j] = mat2[i][j];
    }
}

void spin() {  // 반시계 90도 회전
    int mat2[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            mat2[i][j] = mat[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            mat2[n - 1 - j][i] = mat[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            mat[i][j] = mat2[i][j];
    }
}

void solve() {
    while (1) {
        int mx = 0, r_mx = 0, ri = 0, rj = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] > 0) {
                    pair<int, int> p = bfs(i, j);
                    int score = p.first + p.second;
                    if (score >= mx + r_mx) {
                        if (score == mx + r_mx) {
                            if (p.second >= r_mx) {
                                mx = p.first;
                                r_mx = p.second;
                                ri = i;
                                rj = j;
                            }
                        }
                        else {
                            mx = p.first;
                            r_mx = p.second;
                            ri = i;
                            rj = j;
                        }
                    }
                    init();
                }
            }
        }
        if (mx + r_mx < 2)  // 그룹이 형성되지 않는 경우
            break;

        res += (mx + r_mx) * (mx + r_mx);  // 점수 추가
        bool chk = 0;
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {  
                if (i == ri && j == rj)
                    bfs2(i, j);
            }
        }
        gravity();
        spin();
        gravity();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
                visited2[i][j] = 0;
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