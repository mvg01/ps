#include <bits/stdc++.h>
using namespace std;

int n, k, a[100001], b[100001], ans = 0;
void solve()
{
    int s = 0, e = 1e9, mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] + mid >= b[i])
                cnt++;
        }
        if (cnt >= k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    cout << ans;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}