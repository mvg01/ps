#include <bits/stdc++.h>
using namespace std;

int n, m, v[100005], s[400005];

int init(int l, int r, int idx)
{
    if (l == r)
        return s[idx] = v[l];
    int mid = (l + r) / 2;
    return s[idx] = min(init(l, mid, idx * 2), init(mid + 1, r, idx * 2 + 1));
}

int update(int index, int value, int l, int r, int idx)
{
    if (l > index || r < index)
        return s[idx];
    if (l == r)
        return v[index] = s[idx] = value;
    int mid = (l + r) / 2;
    return s[idx] = min(update(index, value, l, mid, idx * 2), update(index, value, mid + 1, r, idx * 2 + 1));
}

int query(int l, int r, int il, int ir, int idx)
{
    if (l > ir || r < il)
        return 2e9;
    if (l <= il && r >= ir)
        return s[idx];
    int mid = (il + ir) / 2;
    return min(query(l, r, il, mid, idx * 2), query(l, r, mid + 1, ir, idx * 2 + 1));
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    init(1, n, 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c, 1, n, 1);
        else
            cout << query(b, c, 1, n, 1) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}