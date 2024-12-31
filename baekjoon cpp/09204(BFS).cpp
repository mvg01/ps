#include <bits/stdc++.h>
using namespace std;

int t, sy, sx, ey, ex;
int d[4][2] = { {-1,-1},{-1,1},{1,-1},{1,1} };
bool v[9][9];
pair<int, int>p[9][9];

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            v[i][j] = 0;
            p[i][j] = { -1,-1 };
        }
    }
    queue<tuple<int, int, int>>q;
    q.push({ sy,sx,0 });
    while (q.size()) {
        auto [y, x, cnt] = q.front();
        q.pop();
        if (y == ey && x == ex) {
            cout << cnt << ' ';
            vector<pair<int, int>>ans;
            ans.push_back({ ey,ex });
            int ty = ey, tx = ex;
            if (ey != sy || ex != sx) {
                while (1) {
                    if (ty == sy && tx == sx)
                        break;
                    ans.push_back({ p[ty][tx].first, p[ty][tx].second });
                    int uy = ty, ux = tx;
                    ty = p[uy][ux].first;
                    tx = p[uy][ux].second;
                }
            }
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << (char)(ans[i].second + 'A' - 1) << ' ' << ans[i].first << ' ';
            cout << '\n';
            return;
        }
        if (cnt == 4)
            continue;
        for (int i = 0; i < 4; i++) {
            int ty = y, tx = x;
            while (1) {
                int yy = ty + d[i][0];
                int xx = tx + d[i][1];
                if (yy > 8 || yy <= 0 || xx > 8 || xx <= 0) break;
                if (v[yy][xx]) break;
                q.push({ yy,xx,cnt + 1 });
                p[yy][xx] = { y,x };
                v[yy][xx] = 1;
                ty = yy;
                tx = xx;
            }

        }
    }
    cout << "Impossible\n";
}

void input() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        char a, b;
        cin >> a >> sy >> b >> ey;
        sx = a - 'A' + 1;
        ex = b - 'A' + 1;
        solve();
    }
}  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}