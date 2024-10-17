#include <bits/stdc++.h>
using namespace std;

int t, h, w, o, f, sx, sy, ex, ey;
int mat[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ sy,sx,f });
    visited[sy][sx] = 1;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int cf = get<2>(q.front());  // 남은 힘
        q.pop();
        if (y == ey && x == ex) {
            cout << "잘했어!!\n";
            return;
        }
        if (cf == 0)
            continue;
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy >= w || yy < 0 || xx >= h || xx < 0)  // w와 h가 반대인 이유 ? 
                continue;
            if (visited[yy][xx])
                continue;
            if (cf >= mat[yy][xx] - mat[y][x]) {
                visited[yy][xx] = 1;
                q.push({ yy,xx,cf - 1 });
            }
        }
    }
    cout << "인성 문제있어??\n";
}

void input() {
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> h >> w >> o >> f >> sx >> sy >> ex >> ey;
        for (int i = 0; i < o; i++) {
            cin >> a >> b >> c;
            a--; b--;
            mat[b][a] = c;
        }
        sx--; sy--; ex--; ey--;
        solve();
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                mat[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}