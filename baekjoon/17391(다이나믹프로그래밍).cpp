#include <iostream>
using namespace std;

int n, m;
int mat[301][301];
int dp[301][301];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            dp[i][j] = 90001;
        }
    }
}

void solve() {
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i + 1; k <= i + mat[i][j]; k++) 
                dp[k][j] = min(dp[k][j], dp[i][j] + 1);
            
            for (int k = j + 1; k <= j + mat[i][j]; k++) 
                dp[i][k] = min(dp[i][k], dp[i][j] + 1);  
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