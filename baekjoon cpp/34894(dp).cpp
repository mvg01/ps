#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;
ll a[300001], dp[300001][5], ans = 1e14;
char x[5] = {'U', 'O', 'S', 'P', 'C'};

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            dp[i][j] = 1e13;
    }
    if (s[0] == 'U')
        dp[0][0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'U')
            dp[i][0] = min(dp[i - 1][0], a[i]);
        else
            dp[i][0] = dp[i - 1][0];
        for (int j = 1; j < 5; j++)
        {
            if (s[i] == x[j])
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
        if (dp[i][4] != 1e13)
            ans = min(ans, dp[i][4]);
    }
    if (ans == 1e14)
        ans = -1;
    cout << ans;
}

void input()
{
    cin >> n >> s;
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