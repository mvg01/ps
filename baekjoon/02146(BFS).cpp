#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 이 문제가 어렵다면 5931을 먼저 풀어보기

int n, m = 0, res = 10000;
int mat[101][101];
int kind[101][101];
int visited[101][101];
int dy[4] = { 0,1,-1,0 };
int dx[4] = { -1,0,0,1 };

void bfs(int y, int x) {
    m++;
    kind[y][x] = m;
    queue<pair<int, int>>q;
    q.push({ y,x });
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ry = yy + dy[i];
            int rx = xx + dx[i];
            if (ry >= n || ry < 0 || rx >= n || rx < 0)
                continue;
            if (kind[ry][rx])
                continue;
            if (mat[ry][rx] == 1) {
                q.push({ ry,rx });
                kind[ry][rx] = m;
            }
        }
    }
}

void bfs2(int y,int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    int k = kind[y][x];
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        int dis = visited[yy][xx];
        q.pop();
        if (mat[yy][xx] == 1 && kind[yy][xx] != k) {
            res = min(res, dis - 2);
            return;
        }
        if (dis > res + 1)  // 쓸데 없는 곳 탐지 안함
            break;
        for (int i = 0; i < 4; i++) {
            int ry = yy + dy[i];
            int rx = xx + dx[i];
            if (ry >= n || ry < 0 || rx >= n || rx < 0)
                continue;
            if (kind[ry][rx] == k || visited[ry][rx])
                continue;
            q.push({ ry,rx });
            visited[ry][rx] = dis + 1;
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && !kind[i][j])
                bfs(i, j);  // 섬 분류
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                bfs2(i, j);
            }
        }
    }
    cout << res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}