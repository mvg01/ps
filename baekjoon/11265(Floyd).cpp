#include <bits/stdc++.h>
using namespace std;

int n, t;
int mat[501][501];

void input() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
}

void solve() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
    }
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (mat[a][b] <= c) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
