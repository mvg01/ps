#include <bits/stdc++.h>
using namespace std;

int n, k, a[5001], ans;

void solve()
{
    sort(a, a + n, greater<int>());
    for (int i = 0; i < k; i++)
    {
        ans += a[i] - i;
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