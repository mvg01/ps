#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, ans;
void solve()
{
    ll start = 0, end = n * n, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += min(n, mid / i);
        if (cnt < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}