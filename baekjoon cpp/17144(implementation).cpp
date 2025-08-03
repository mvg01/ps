#include <bits/stdc++.h>
using namespace std;

int r, c, t, mat[51][51], ans;
int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void solve() {
    int air = 0;
    for (int i = 0; i < r; i++) {
        if (mat[i][0] == -1) {
            air = i;
            break;
        }
    }
    while (t--) {
        int temp[51][51], h[51][51];
        vector<tuple<int, int, int>>m;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == -1) {
                    temp[i][j] = -1;
                    continue;
                }
                if (mat[i][j] > 4)
                    m.push_back({ i,j,mat[i][j] });
                temp[i][j] = mat[i][j];
                h[i][j] = 0;
            }
        }
        for (int i = 0; i < m.size(); i++) {
            auto [y, x, cnt] = m[i];
            int d_cnt = 0;  // 확산된 방향의 개수
            for (int j = 0; j < 4; j++) {
                int yy = y + d[j][0];
                int xx = x + d[j][1];
                if (yy >= r || yy < 0 || xx >= c || xx < 0)
                    continue;
                if (mat[yy][xx] == -1)
                    continue;
                temp[yy][xx] += mat[y][x] / 5;
                h[yy][xx] += mat[y][x] / 5;
                d_cnt++;
            }
            temp[y][x] = mat[y][x] - mat[y][x] / 5 * d_cnt + h[y][x];
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                //cout << temp[i][j] << ' ';
                mat[i][j] = temp[i][j];
            }
            //cout << '\n';
        }

        // 윗공기 회전
        temp[air][1] = 0;
        for (int j = 2; j < c; j++)
            temp[air][j] = mat[air][j - 1];
        for (int j = air - 1; j >= 0; j--)
            temp[j][c - 1] = mat[j + 1][c - 1];
        for (int j = c - 2; j >= 0; j--)
            temp[0][j] = mat[0][j + 1];
        for (int j = 1; j < air; j++)
            temp[j][0] = mat[j - 1][0];
        temp[air][0] = -1;

        // 아랫공기 회전
        temp[air + 1][1] = 0;
        for (int j = 2; j < c; j++)
            temp[air + 1][j] = mat[air + 1][j - 1];
        for (int j = air + 2; j < r; j++)
            temp[j][c - 1] = mat[j - 1][c - 1];
        for (int j = c - 2; j >= 0; j--)
            temp[r - 1][j] = mat[r - 1][j + 1];
        for (int j = r - 2; j > air; j--)
            temp[j][0] = mat[j + 1][0];
        temp[air + 1][0] = -1;

        ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                //cout << temp[i][j] << ' ';
                mat[i][j] = temp[i][j];
                ans += mat[i][j];
            }
            //cout << '\n';
        }
    }
    cout << ans + 2;
}

void input() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> mat[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}