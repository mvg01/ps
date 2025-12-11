#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[50005], sx[200005], sn[200005];

int mx_init(int l, int r, int idx)
{
    if (l == r)
        return sx[idx] = v[l];
    int mid = (l + r) / 2;
    return sx[idx] = max(mx_init(l, mid, idx * 2), mx_init(mid + 1, r, idx * 2 + 1));
}

int mn_init(int l, int r, int idx)
{
    if (l == r)
        return sn[idx] = v[l];
    int mid = (l + r) / 2;
    return sn[idx] = min(mn_init(l, mid, idx * 2), mn_init(mid + 1, r, idx * 2 + 1));
}

pair<int, int> query(int l, int r, int il, int ir, int idx)
{
    if (ir < l || il > r)
        return {-1e9, 1e9};
    if (il >= l && ir <= r)
        return {sx[idx], sn[idx]};
    int mid = (il + ir) / 2;
    pair<int, int> left = query(l, r, il, mid, idx * 2);
    pair<int, int> right = query(l, r, mid + 1, ir, idx * 2 + 1);
    int curmax = max(left.first, right.first);
    int curmin = min(left.second, right.second);
    return {curmax, curmin};
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    mx_init(1, n, 1);
    mn_init(1, n, 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> ans = query(a, b, 1, n, 1);
        cout << ans.first - ans.second << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}