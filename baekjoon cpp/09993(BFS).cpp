#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 1;
char mat[1001][1001];
int d1[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };  // '/' 의 북서남동
int d2[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };  // '\' 의 북서남동
bool vis[1001][1001][4];

void bfs(int y, int x, int dir) {
    queue<tuple<int, int, int, int>>q;
    q.push({ y,x,dir,1 });
    vis[y][x][dir] = 1;
    while (q.size()) {
        int yy = get<0>(q.front());
        int xx = get<1>(q.front());
        int d = get<2>(q.front());
        int p = get<3>(q.front());
        q.pop();
        int dy, dx, tmpdir;   // tmpdir은 튕겨지는 곳의 방향
        if (mat[yy][xx] == '/') {
            dy = d1[d][0] + yy;
            dx = d1[d][1] + xx;
            if (d == 0)
                tmpdir = 3;
            else if (d == 1)
                tmpdir = 2;
            else if (d == 2)
                tmpdir = 1;
            else
                tmpdir = 0;
        }
        else {
            dy = d2[d][0] + yy;
            dx = d2[d][1] + xx;
            if (d == 0)
                tmpdir = 1;
            else if (d == 1)
                tmpdir = 0;
            else if (d == 2)
                tmpdir = 3;
            else
                tmpdir = 2;
        }
        if (dy < 0 || dy >= n || dx < 0 || dx >= m) continue;
        if (vis[dy][dx][tmpdir]) continue;  // 애초에 무한히 돌 수 없음
        q.push({ dy,dx,tmpdir,p + 1 });
        ans = max(ans, p + 1);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0)  // 북에서
                bfs(i, j, 0);
            if (j == 0)  // 서에서
                bfs(i, j, 1);  
            if (i == n - 1)  // 남에서
                bfs(i, j, 2);
            if (j == m - 1)  // 동에서 
                bfs(i, j, 3);
        }
    }
    cout << ans;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}