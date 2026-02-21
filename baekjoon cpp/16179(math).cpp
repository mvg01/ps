#include <bits/stdc++.h>
#define MOD 9973
using namespace std;

int t, n, a[101];
int dp[101], p[101];

void solve()
{
    for (int i = 1; i < 101; i++)
        a[i] = i;
    for (int i = 2; i < 101; i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = i * 2; j < 101; j += i)
            a[j] = 0;
    }
    int cnt = 0;
    for (int i = 2; i <= 100; i++)
        if (a[i] == i)
            cnt++;

    p[0] = 1;
    for (int i = 1; i <= 100; i++)
        p[i] = p[i - 1] * 10 % MOD;
    for (int i = 4; i <= 100; i++)
    {
        int x = (45 * p[i - 2]) % MOD;                // 0제외한 앞자리 수 합 짝수 * 남은 수들
        int y = (((cnt * p[i - 3]) % MOD) * 9) % MOD; // 앞자리 0을 제외한(9), 소수 경우의 수 * 남은 수들
        int xy = (((45 * cnt) % MOD) * (p[i - 4])) % MOD;
        dp[i] = (x + y - xy) % MOD;
        if (dp[i] < 0)
            dp[i] += MOD;
    }
}

void input()
{
    cin >> t;
    solve();
    while (t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}