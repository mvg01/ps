#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int par[100001];

int getp(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = getp(par[x]);
}

void setunion(int a, int b)
{
    a = getp(a);
    b = getp(b);
    if (a < b)
        par[b] = a;
    else
        par[a] = b;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (getp(i) != getp(1))
        {
            ans++;
            setunion(i, 1);
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (getp(u) != getp(v))
            setunion(u, v);
        else
            ans++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}