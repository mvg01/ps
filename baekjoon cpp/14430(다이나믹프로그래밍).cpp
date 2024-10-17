#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int mat[301][301];
int dp[301][301];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    }
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(mat[i][j] + dp[i][j - 1], dp[i][j]);
            dp[i][j] = max(mat[i][j] + dp[i - 1][j], dp[i][j]);
        }
    }
    cout << dp[n][m];
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}