#include <bits/stdc++.h>
using namespace std;

int n, a[21], b[21];
int dp[21][101];

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (j >= a[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + b[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][99];
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}