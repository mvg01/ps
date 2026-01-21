#include <bits/stdc++.h>
using namespace std;

int n, c, x[2000001], ans;

void solve()
{
    sort(x, x + n);
    int l = 0, r = 1e9, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int cnt = 0, temp = x[0];
        for (int i = 1; i < n; i++)
        {
            if (x[i] - temp >= mid)
            {
                temp = x[i];
                cnt++;
            }
        }
        if (cnt >= c - 1)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
}

void input()
{
    cin >> n >> c;
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