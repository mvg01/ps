#include <bits/stdc++.h>
using namespace std;

int n, k, q, m, b[5005], c[5005], d[5005];
bool a[5005];

void solve()
{
    for (int i = 0; i < q; i++)
    {
        if (a[b[i]])
            continue;
        for (int j = b[i]; j <= n + 2; j += b[i])
        {
            if (a[j])
                continue;
            c[j] = 1;
        }
    }
    for (int i = 3; i <= n + 2; i++)
    {
        if (c[i] == 0)
            d[i] = d[i - 1] + 1;
        else
            d[i] = d[i - 1];
    }
}

void input()
{
    cin >> n >> k >> q >> m;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 0; i < q; i++)
        cin >> b[i];
    solve();
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << d[e] - d[s - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}