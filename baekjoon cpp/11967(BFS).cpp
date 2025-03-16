#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
vector<pair<int, int>>mat[101][101];
bool light[101][101], vis[101][101];
int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

void solve() {
    queue<pair<int, int>>q;
    light[1][1] = 1;
    vis[1][1] = 1;
    q.push({ 1,1 });
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < mat[y][x].size(); i++) {
            int yy = mat[y][x][i].first;
            int xx = mat[y][x][i].second;
            if (!light[yy][xx]) ans++;
            if (vis[yy][xx] && !light[yy][xx]) 
                q.push({ yy,xx });
            light[yy][xx] = 1;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy > n || yy <= 0 || xx > n || xx <= 0)
                continue;
            if (vis[yy][xx])
                continue;
            if (light[yy][xx]) {
                q.push({ yy,xx });
            }
            vis[yy][xx] = 1;
        }
    }
    cout << ans;
}

void input() {
    int x, y, a, b, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        mat[y][x].push_back({ b,a });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}