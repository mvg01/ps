#include <bits/stdc++.h>
using namespace std;

int mat[6][6];
int visited[6][6];
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int r, c;

void init() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            visited[i][j] = 0;
    }
}

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ r,c,0 });
    visited[r][c] = 1;
    int chk = 1;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        if (mat[y][x] == chk) {
            if (chk == 6) {
                cout << t;
                return;
            }
            chk++;
            init();
            while (q.size()) 
                q.pop();
            visited[y][x] = 1;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= 5 || yy < 0 || xx >= 5 || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] != -1) {
                q.push({ yy,xx, t + 1 });
                visited[yy][xx] = 1;
            }
        }
    }
    cout << -1;
}

void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) 
            cin >> mat[i][j];
    }
    cin >> r >> c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}