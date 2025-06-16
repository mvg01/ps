#include <bits/stdc++.h>
using namespace std;

int n, t, k[101], s[101];
int dp[101][10001];

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (k[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k[i - 1]] + s[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][t];
}

void input()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> k[i] >> s[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}