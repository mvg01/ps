#include <bits/stdc++.h>
using namespace std;

int n, k, a[100001], ans = 1e9;

void solve()
{
    int l = 0, r = 1e9, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        bool no = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= mid)
                cnt = 0;
            else
                cnt++;
            if (cnt >= k)
            {
                no = 1;
                break;
            }
        }
        if (no)
            l = mid + 1;
        else
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
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