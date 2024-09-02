#include <bits/stdc++.h>
using namespace std;

int n;
int mat[11][11];
int visited[11][11];
int d[5][2] = { {-1,0},{0,-1},{0,0},{0,1},{1,0} };
int res = 1000000000;

void bt(int cnt, int cost) {
    if (cnt == 3) {
        res = min(res, cost);
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            bool chk = 0;
            for (int k = 0; k < 5; k++) {
                if (visited[i + d[k][0]][j + d[k][1]]) {
                    chk = 1;
                    break;
                }
            }
            if (!chk) {
                int c = 0;
                for (int k = 0; k < 5; k++) {
                    visited[i + d[k][0]][j + d[k][1]] = 1;
                    c += mat[i + d[k][0]][j + d[k][1]];
                }
                bt(cnt + 1, cost + c);
                for (int k = 0; k < 5; k++)
                    visited[i + d[k][0]][j + d[k][1]] = 0;
            }
        }
    }
}

void solve() {
    bt(0, 0);
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