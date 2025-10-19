#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll a[300001], sum;

void solve()
{
    ll ans = 0;
    sum *= -1;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < sum)
        {
            ans += sum;
            ll temp = sum;
            sum *= -1;
            sum -= a[i];
            sum += temp;
            sum *= -1;
        }
        else
            ans += a[i];
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}