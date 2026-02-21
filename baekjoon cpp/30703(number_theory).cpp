#include <bits/stdc++.h>
using namespace std;

int n, a[100001], b[100001], x[100001];
void solve()
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int t = abs(a[i] - b[i]);
        if (t % x[i] > 0)
        {
            cout << -1;
            return;
        }
        mx = max(mx, t / x[i]);
    }
    bool odd = 0;
    if (mx % 2)
        odd = 1;
    for (int i = 0; i < n; i++)
    {
        int t = abs(a[i] - b[i]);
        if (odd && (t / x[i]) % 2 == 0)
        {
            cout << -1;
            return;
        }
        if (!odd && (t / x[i]) % 2 == 1)
        {
            cout << -1;
            return;
        }
    }
    cout << mx;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}