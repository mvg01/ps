#include <iostream>
#define MOD 987654321
using namespace std;
using ll = long long;

int n;
ll dp[100001][10];

void input() {
    cin >> n;
}

void solve() {
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {  // 1의 자리 숫자가 j
            for (int k = -2; k <= 2; k++) {
                if (j + k >= 1 && j + k <= 9)
                    dp[i][j] += dp[i - 1][j + k] % MOD;
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= 9; i++)
        res += dp[n][i] % MOD;
    cout << res % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}