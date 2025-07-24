#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, t[100001];
ll sum[100001], ans;

void solve()
{
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + t[i];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ll temp = sum[a - 1];
        if (temp < c)
        {
            ll k = (c - temp + sum[n] - 1) / sum[n];
            temp += k * sum[n];
        }
        if (a < b)
        {
            temp += sum[b - 1] - sum[a - 1];
        }
        else
        {
            temp += sum[n] - sum[a - 1] + sum[b - 1];
        }
        ans = max(ans, temp);
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}