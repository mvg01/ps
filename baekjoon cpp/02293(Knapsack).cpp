#include <bits/stdc++.h>
using namespace std;

int n, k, a[101];
int dp[10001];

void solve()
{
    sort(a, a + n);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= k; j++)
        {
            if (dp[j - a[i]] != 0)
                dp[j] += dp[j - a[i]];
        }
    }
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