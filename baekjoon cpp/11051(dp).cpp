#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[1001][1001];

void solve()
{
    for (int i = 1; i <= 1000; i++)
    {
        dp[i][1] = i;
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 2; j <= i - 1; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
        }
    }
    cout << dp[n][k] % 10007;
}

void input()
{
    cin >> n >> k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}