#include <bits/stdc++.h>
using namespace std;

int n, s, m, v[51], dp[51][1001];

void solve()
{
    dp[0][s] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (dp[i - 1][j])
            {
                if (j + v[i] <= m)
                    dp[i][j + v[i]] = 1;
                if (j - v[i] >= 0)
                    dp[i][j - v[i]] = 1;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= m; i++)
    {
        if (dp[n][i])
            ans = i;
    }
    cout << ans;
}

void input()
{
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}