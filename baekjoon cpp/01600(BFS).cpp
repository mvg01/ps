#include <bits/stdc++.h>
using namespace std;

int k, w, h;
int mat[201][201], vis[201][201][31];
int d1[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int d2[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };

void solve() {
    queue<tuple<int, int, int, int>>q;
    q.push({ 0,0,0,0 });  // y,x,능력사용,움직임
    vis[0][0][0] = 1;
    while (q.size()) {
        auto [y, x, kk, cnt] = q.front();
        q.pop();
        if (y == h - 1 && x == w - 1) {  
            // 목표지점 도착시, 비용을 능력써서 간 비용으로 최대한 전환
            int used = min(kk, cnt / 3); // 말 이동으로 대체 가능한 횟수
            int ans = used + (cnt / 3 - used) * 3 + (cnt % 3);
            cout << ans;
            return;
        }
        int yy, xx, go = 0;
        for (int i = 0; i < 4; i++) {
            yy = d1[i][0] + y;
            xx = d1[i][1] + x;
            if (yy >= h || yy < 0 || xx >= w || xx < 0) 
                continue;
            if (vis[yy][xx][kk])
                continue;
            if (mat[yy][xx] == 0) {
                q.push({ yy,xx,kk,cnt + 1 });
                vis[yy][xx][kk] = 1;
            }
        }
        if (kk < k) {
            for (int i = 0; i < 8; i++) {
                yy = d2[i][0] + y;
                xx = d2[i][1] + x;
                if (yy >= h || yy < 0 || xx >= w || xx < 0)
                    continue;
                if (vis[yy][xx][kk + 1])
                    continue;
                if (mat[yy][xx] == 0) {
                    q.push({ yy,xx,kk + 1,cnt + 3 });
                    vis[yy][xx][kk + 1] = 1;
                }
            }
        }
    }
    cout << -1;
}

void input() {
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++) cin >> mat[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}