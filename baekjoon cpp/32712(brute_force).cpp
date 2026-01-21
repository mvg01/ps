#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, a[200001], ans;

void solve()
{
    ll temp = 0;
    for (ll i = 0; i < min(n, k); i++)
    {
        ans = max(ans, temp + a[i] * (k - i));
        temp += a[i];
    }
    reverse(a, a + n);
    temp = 0;
    for (ll i = 0; i < min(n, k); i++)
    {
        ans = max(ans, temp + a[i] * (k - i));
        temp += a[i];
    }
    cout << ans;
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