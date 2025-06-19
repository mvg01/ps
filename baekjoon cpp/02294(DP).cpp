#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int n, k, a[101];
int dp[100001];

void solve()
{
    for (int i = 0; i <= k; i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= k; j++)
        {
            if (dp[j - a[i]] != INF)
                dp[j] = min(dp[j - a[i]] + 1, dp[j]);
        }
    }
    if (dp[k] == INF)
        dp[k] = -1;
    cout << dp[k];
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}