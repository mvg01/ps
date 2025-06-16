#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[21];
int dp[10001];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        dp[a[i]] += 1;
        for (int j = a[i]; j <= m; j++)
        {
            if (dp[j - a[i]] != 0)
                dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m] << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 10001; i++)
            dp[i] = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}