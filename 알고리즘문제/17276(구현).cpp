#include <bits/stdc++.h>
using namespace std;
int t, n, d;
int mat[501][501];

void solve() {
    if (d > 0)
        d -= 360;
    d *= -1;
    d /= 45;
    for (int i = 0; i < d; i++) {  // 반시계 방향 회전 구현
        int m = n, p = 0, idx;
        while (1) {
            if (m == 1)
                break;
            idx = m / 2;
            int s = mat[p][p];
            mat[p][p] = mat[p][p + idx];
            mat[p][p + idx] = mat[p][p + idx * 2];
            mat[p][p + idx * 2] = mat[p + idx][p + idx * 2];
            mat[p + idx][p + idx * 2] = mat[p + idx * 2][p + idx * 2];
            mat[p + idx * 2][p + idx * 2] = mat[p + idx * 2][p + idx];
            mat[p + idx * 2][p + idx] = mat[p + idx * 2][p];
            mat[p + idx * 2][p] = mat[p + idx][p];
            mat[p + idx][p] = s;
            m -= 2;
            p++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}