#include <bits/stdc++.h>
#define INF 2e9
using namespace std;

int n, m, v[100005], s[400005];

int init(int l, int r, int idx)
{
    if (l == r)
        return s[idx] = l;
    int mid = (l + r) / 2;
    int leftidx = init(l, mid, idx * 2);
    int rightidx = init(mid + 1, r, idx * 2 + 1);
    if (v[leftidx] > v[rightidx])
        return s[idx] = rightidx;
    else
        return s[idx] = leftidx;
}

int update(int index, int value, int l, int r, int idx)
{
    if (l > index || r < index)
        return s[idx];
    if (index == l && l == r)
    {
        v[index] = value;
        return s[idx] = index;
    }
    int mid = (l + r) / 2;
    int leftidx = update(index, value, l, mid, idx * 2);
    int rightidx = update(index, value, mid + 1, r, idx * 2 + 1);
    if (v[leftidx] > v[rightidx])
        return s[idx] = rightidx;
    else
        return s[idx] = leftidx;
}

int query(int l, int r, int il, int ir, int idx)
{
    if (l > ir || r < il)
        return 100004;
    if (l <= il && r >= ir)
        return s[idx];
    int mid = (il + ir) / 2;
    int leftidx = query(l, r, il, mid, idx * 2);
    int rightidx = query(l, r, mid + 1, ir, idx * 2 + 1);
    if (v[leftidx] > v[rightidx])
        return rightidx;
    else if (v[leftidx] > v[rightidx])
        return leftidx;
    else
    {
        if (leftidx > rightidx)
            return rightidx;
        else
            return leftidx;
    }
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    init(1, n, 1);
    v[100004] = INF;
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