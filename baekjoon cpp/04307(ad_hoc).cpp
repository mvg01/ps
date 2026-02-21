#include <bits/stdc++.h>
using namespace std;

int t, n, l, a[100001];

void solve()
{
    sort(a, a + n);
    int y = 0, x = 0;
    x = max(a[n - 1], l - a[0]);
    for (int i = 0; i < n; i++)
    {
        y = max(y, min(a[i], l - a[i]));
    }
    cout << y << ' ' << x << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> l >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}