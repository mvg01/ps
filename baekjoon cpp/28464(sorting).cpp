#include <bits/stdc++.h>
using namespace std;

int n, a[200001];

void solve()
{
    sort(a, a + n, greater<int>());
    long long ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            ans1 += a[i];
        else
            ans2 += a[i];
    }
    if (n % 2 == 1)
    {
        ans1 += a[n / 2];
        ans2 -= a[n / 2];
    }
    cout << ans2 << ' ' << ans1;
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