#include <iostream>
using namespace std;
using ll = long long;

int n, mat[101][101];
ll dp[101][101];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
}

void solve() {
    ll p = mat[0][0];
    dp[p][0] = 1;
    dp[0][p] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n - 1 && j == n - 1)
                break;
            if (dp[i][j] >= 1) {
                ll m = mat[i][j];
                if (i + m < n)
                    dp[i + m][j] += dp[i][j];
                if (j + m < n)
                    dp[i][j + m] += dp[i][j];
            }
        }
    }
    cout << dp[n - 1][n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}