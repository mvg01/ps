#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[1000001];

void solve()
{
    int s = 1, e = 1e9, mid, ans = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= mid)
                cnt += a[i] / mid;
            if (cnt >= m)
                break;
        }
        if (cnt >= m)
        {
            ans = max(ans, mid);
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << ans;
}

void input()
{
    cin >> m >> n;
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