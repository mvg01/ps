#include <bits/stdc++.h>
using namespace std;

int n, a[1001], ans;
int dp[1001], dp2[1001];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        dp2[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i] + dp2[i] - 1);
    cout << ans;
}

void input()
{
    cin >> n;
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