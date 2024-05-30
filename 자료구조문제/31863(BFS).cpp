#include <bits/stdc++.h>
using namespace std;

int n, m, r1=0, r2=0;
int mat[1001][1001];
int d[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
bool v[1001][1001];
queue<tuple<int, int, bool>>q;
void input() {
    char c;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '@') {
                q.push({ i,j,1 });
                v[i][j] = 1;
                mat[i][j] = 0;
            }
            else if (c == '.')
                mat[i][j] = 0;
            else if (c == '|')
                mat[i][j] = 9999999;
            else if (c == '*') {
                mat[i][j] = 1;
                r1++;
            }
            else if (c == '#') {
                mat[i][j] = 2;
                r1++;
            }
        }
    }
}

void solve() {
    while(!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        bool t = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (v[yy][xx])
                continue;
            if (mat[yy][xx] <= 2) {  // 본진 || 여진
                mat[yy][xx]--;
                if (mat[yy][xx] == 0) {
                    q.push({ yy,xx,0 });
                    v[yy][xx] = 1;
                    r2++;
                }
            }
            if (t && mat[yy][xx] <= 2) {  // 본진
                yy += d[i][0];
                xx += d[i][1];
                if (yy >= n || yy < 0 || xx >= m || xx < 0)
                    continue;
                if (v[yy][xx])
                    continue;
                mat[yy][xx]--;
                if (mat[yy][xx] == 0) {
                    q.push({ yy,xx,0 });
                    v[yy][xx] = 1;
                    r2++;
                }
            }
        }
    }
    cout << r2 << ' ' << r1 - r2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}