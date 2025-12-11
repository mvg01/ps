#include <bits/stdc++.h>
#define INF 1e9 + 9
using namespace std;

int n, m, k;
int v[100001];
int mn[400005], mx[400005];

int min_init(int l, int r, int idx)
{
    if (l == r)
        return mn[idx] = v[l];
    int mid = (l + r) / 2;
    return mn[idx] = min(min_init(l, mid, idx * 2), min_init(mid + 1, r, idx * 2 + 1));
}

int max_init(int l, int r, int idx)
{
    if (l == r)
        return mx[idx] = v[l];
    int mid = (l + r) / 2;
    return mx[idx] = max(max_init(l, mid, idx * 2), max_init(mid + 1, r, idx * 2 + 1));
}

int min_query(int l, int r, int idx, int il, int ir)
{
    if (l > ir || r < il)
        return INF;
    if (l <= il && r >= ir)
        return mn[idx];
    int mid = (il + ir) / 2;
    return min(min_query(l, r, idx * 2, il, mid), min_query(l, r, idx * 2 + 1, mid + 1, ir));
}

int max_query(int l, int r, int idx, int il, int ir)
{
    if (l > ir || r < il)
        return 0;
    if (l <= il && r >= ir)
        return mx[idx];
    int mid = (il + ir) / 2;
    return max(max_query(l, r, idx * 2, il, mid), max_query(l, r, idx * 2 + 1, mid + 1, ir));
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 0; i < 400005; i++)
        mn[i] = INF;
    min_init(1, n, 1);
    max_init(1, n, 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << min_query(a, b, 1, 1, n) << ' ' << max_query(a, b, 1, 1, n) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}