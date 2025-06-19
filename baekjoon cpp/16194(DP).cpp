#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int n, v[1001], w[1001], dp[1001];

void solve()
{
    for (int i = 0; i <= n; i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = w[i]; j <= n; j++)
        {
            if (dp[j - w[i]] != INF)
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[n];
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        w[i] = i + 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}