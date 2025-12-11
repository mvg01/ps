#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;

int t, l;
ll dp[5001];
void solve()
{
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 2;
    for (int i = 6; i <= 5000; i += 2)
    {
        for (int j = 0; j < i; j += 2)
        {
            dp[i] += dp[j] * dp[i - 2 - j];
            dp[i] %= MOD;
        }
    }
}

void input()
{
    cin >> t;
    solve();
    while (t--)
    {
        cin >> l;
        cout << dp[l] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}