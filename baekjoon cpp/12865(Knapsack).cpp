#include <bits/stdc++.h>
using namespace std;

int n, k, w[101], v[101];
int dp[101][100001];

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}