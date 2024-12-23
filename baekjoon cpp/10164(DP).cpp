#include <bits/stdc++.h>
using namespace std;

//시작지점에서 k까지 경우의수 * k 부터 끝 지점 까지 경우의 수

int n, m, k;
int mat[17][17];
void solve() {
    // k값 2차원 상 처리
    int y = (k - 1) / m + 1;
    int x = k % m;
    if (x == 0 && k != 0)
        x = m;
    if (k == 0) {
        y = 0;
        x = 0;
    }
    for (int i = 1; i <= m; i++) 
        mat[1][i] = 1;
    for (int i = 1; i <= n; i++)
        mat[i][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) 
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
    }
    if (y != 0 && x != 0) {
        int temp = mat[y][x];
        for (int i = x; i <= m; i++)
            mat[y][i] = 1;
        for (int i = y; i <= n; i++)
            mat[i][x] = 1;
        for (int i = y + 1; i <= n; i++) {
            for (int j = x + 1; j <= m; j++) 
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
        }
        cout << temp * mat[n][m];
    }
    else
        cout << mat[n][m];
}

void input() {
    cin >> n >> m >> k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}