#include <bits/stdc++.h>
using namespace std;

int n, a[100001], b[100001], sum[100001], ans;
void solve()
{
    sum[0] = a[0];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            sum[i - 1] = max(0, sum[i - 1]);
        sum[i] = sum[i - 1] + a[i];
        ans = max(ans, sum[i]);
    }
    sum[0] = b[0];
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 1)
            sum[i - 1] = max(0, sum[i - 1]);
        sum[i] = sum[i - 1] + b[i];
        ans = max(ans, sum[i]);
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            a[i] = -1;
        else
            a[i] = 1;

        if (a[i] == 1)
            b[i] = -1;
        else
            b[i] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}