#include <bits/stdc++.h>
using namespace std;

int n, a[100001], dp[100001][3];

void solve()
{
    dp[0][0] = a[0]; // 온전히 먹음
    dp[0][1] = 0;    // 건너 뜀
    dp[0][2] = 0;    // 2번 연속으로 먹음
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][1] + a[i];
        dp[i][1] = max(dp[i - 1][1], max(dp[i - 1][0], dp[i - 1][2]));
        dp[i][2] = dp[i - 1][0] + a[i] / 2;
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
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