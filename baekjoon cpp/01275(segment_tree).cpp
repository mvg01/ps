#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q;
ll v[100005], sum[400005];

ll init(ll l, ll r, ll idx)
{
    if (l == r)
        return sum[idx] = v[l];
    ll mid = (l + r) / 2;
    return sum[idx] = init(l, mid, idx * 2) + init(mid + 1, r, idx * 2 + 1);
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

ll update(ll index, ll value, ll idx, ll l, ll r)
{
    if (index < l || index > r)
        return sum[idx];
    if (l == r)
        return sum[idx] = v[index] = value;
    ll mid = (l + r) / 2;
    return sum[idx] = update(index, value, idx * 2, l, mid) + update(index, value, idx * 2 + 1, mid + 1, r);
}

void input()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    init(1, n, 1);
    for (int i = 0; i < q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);
        cout << query(x, y, 1, 1, n) << '\n';
        update(a, b, 1, 1, n);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}