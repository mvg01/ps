#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int mat[301][301], temp[301][301];
void input() {
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

void f() {
    for (int i = 0; i < min(n, m) / 2; i++) {
        for (int j = i; j < m - 1 - i; j++)
            temp[i][j] = mat[i][j + 1];
        for (int j = i; j < n - 1 - i; j++)
            temp[j][m - 1 - i] = mat[j + 1][m - 1 - i];
        for (int j = m - 1 - i; j > i; j--)
            temp[n - 1 - i][j] = mat[n - 1 - i][j - 1];
        for (int j = n - 1 - i; j > i; j--)
            temp[j][i] = mat[j - 1][i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            mat[i][j] = temp[i][j];
    }
}

void solve() {
    for (int i = 0; i < r; i++)
        f();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}