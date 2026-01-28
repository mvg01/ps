#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, mat[1001][1001], dp[1001][1001], ans;

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
    }
    for (int i = 1; i < n; i++)
        ans += (dp[i][n] + dp[n][i]);
    ans += (dp[n][n] * 2);
    cout << ans << ' ' << n * n;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}