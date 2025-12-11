#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[100005], e[400005], o[400005];

int e_init(int l, int r, int idx)
{
    if (l == r)
    {
        if (v[l] % 2 == 0)
            return e[idx] = 1;
        else
            return e[idx] = 0;
    }
    int mid = (l + r) / 2;
    return e[idx] = e_init(l, mid, idx * 2) + e_init(mid + 1, r, idx * 2 + 1);
}

int o_init(int l, int r, int idx)
{
    if (l == r)
    {
        if (v[l] % 2)
            return o[idx] = 1;
        else
            return o[idx] = 0;
    }
    int mid = (l + r) / 2;
    return o[idx] = o_init(l, mid, idx * 2) + o_init(mid + 1, r, idx * 2 + 1);
}

int e_update(int index, int value, int l, int r, int idx)
{
    if (index < l || index > r)
        return e[idx];
    if (l == r)
    {
        v[index] = value;
        if (v[l] % 2 == 0)
            return e[idx] = 1;
        else
            return e[idx] = 0;
    }
    int mid = (l + r) / 2;
    return e[idx] = e_update(index, value, l, mid, idx * 2) + e_update(index, value, mid + 1, r, idx * 2 + 1);
}

int o_update(int index, int value, int l, int r, int idx)
{
    if (index < l || index > r)
        return o[idx];
    if (l == r)
    {
        v[index] = value;
        if (v[l] % 2)
            return o[idx] = 1;
        else
            return o[idx] = 0;
    }
    int mid = (l + r) / 2;
    return o[idx] = o_update(index, value, l, mid, idx * 2) + o_update(index, value, mid + 1, r, idx * 2 + 1);
}

int e_query(int l, int r, int il, int ir, int idx)
{
    if (ir < l || il > r)
        return 0;
    if (il >= l && ir <= r)
        return e[idx];
    int mid = (il + ir) / 2;
    return e_query(l, r, il, mid, idx * 2) + e_query(l, r, mid + 1, ir, idx * 2 + 1);
}

int o_query(int l, int r, int il, int ir, int idx)
{
    if (ir < l || il > r)
        return 0;
    if (il >= l && ir <= r)
        return o[idx];
    int mid = (il + ir) / 2;
    return o_query(l, r, il, mid, idx * 2) + o_query(l, r, mid + 1, ir, idx * 2 + 1);
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    e_init(1, n, 1);
    o_init(1, n, 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            e_update(b, c, 1, n, 1);
            o_update(b, c, 1, n, 1);
        }
        else if (a == 2)
        {
            cout << e_query(b, c, 1, n, 1) << '\n';
        }
        else
        {
            cout << o_query(b, c, 1, n, 1) << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}