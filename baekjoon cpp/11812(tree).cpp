#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, q;

// k진 트리에서 부모를 구하는 함수
ll parent(ll x)
{
    if (x == 1)
        return 1;
    else
        return (x - 2) / k + 1;
}

void solve()
{
    for (int i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (k == 1)
        {
            cout << abs(x - y) << '\n';
            continue;
        }
        ll ans = 0;
        while (x != y)
        {
            if (x < y)
                swap(x, y);
            x = parent(x);
            ans++;
        }
        cout << ans << '\n';
    }
}

void input()
{
    cin >> n >> k >> q;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}