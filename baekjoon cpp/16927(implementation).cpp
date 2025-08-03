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

void f(int i) {
    int s = mat[i][i];
    for (int j = i; j < m - 1 - i; j++)
        mat[i][j] = mat[i][j + 1];
    for (int j = i; j < n - 1 - i; j++)
        mat[j][m - 1 - i] = mat[j + 1][m - 1 - i];
    for (int j = m - 1 - i; j > i; j--)
        mat[n - 1 - i][j] = mat[n - 1 - i][j - 1];
    for (int j = n - 1 - i; j > i + 1; j--)
        mat[j][i] = mat[j - 1][i];
    mat[i + 1][i] = s;
}

void solve() {
    // (n-1)*2+(m-1)*2 
    int a = n, b = m, idx = 0;
    while (1) {
        int x = (a + b) * 2 - 4;
        int xx = r % x;
        for (int i = 0; i < xx; i++)
            f(idx);
        a -= 2; b -= 2;
        if (min(a, b) == 0)
            break;
        idx++;
    }
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