#include <iostream>
#define MOD  1000000007
using namespace std;

int n, m;
int mat[1001][1001];
long long dp[1001][1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        if (mat[0][i] == 1)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j]) {
                if (j == 0)
                    dp[i][j] = (dp[i - 1][j + 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                else if (j == m - 1)
                    dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                else 
                    dp[i][j] = (dp[i - 1][j + 1] % MOD + dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;  
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < m; i++) {
        res += dp[n - 1][i];
        res %= MOD;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}