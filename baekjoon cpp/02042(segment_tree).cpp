#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
ll v[1000001], sum[4000005];

ll init(ll l, ll r, ll idx)
{
    if (l == r)
        return sum[idx] = v[l];
    ll mid = (l + r) / 2;
    return sum[idx] = init(l, mid, idx * 2) + init(mid + 1, r, idx * 2 + 1);
}

ll change(ll index, ll value, ll idx, ll l, ll r)
{
    if (index < l || index > r)
        return sum[idx];
    if (l == r)
        return sum[idx] = v[index] = value;
    ll mid = (l + r) / 2;
    return sum[idx] = change(index, value, idx * 2, l, mid) + change(index, value, idx * 2 + 1, mid + 1, r);
}

ll query(ll l, ll r, ll idx, ll il, ll ir)
{
    if (l > ir || r < il)
        return 0;
    if (l <= il && r >= ir)
        return sum[idx];
    ll mid = (il + ir) / 2;
    return query(l, r, idx * 2, il, mid) + query(l, r, idx * 2 + 1, mid + 1, ir);
}

void input()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    init(1, n, 1);
    for (int i = 0; i < m + k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            change(b, c, 1, 1, n);
        else
            cout << query(b, c, 1, 1, n) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}