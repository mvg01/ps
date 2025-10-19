#include <bits/stdc++.h>
using namespace std;

int n, m, par[1000001];
bool vis[1000001];

void init()
{
    for (int i = 0; i < 1000001; i++)
        par[i] = i;
}

int getparent(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = getparent(par[x]);
}

void setunion(int a, int b)
{
    a = getparent(a);
    b = getparent(b);
    if (a < b)
        par[b] = a;
    else
        par[a] = b;
}

void solve()
{
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        if (vis[i])
        {
            // 더 작은 부모가 있다면 거기까지 방문처리
            int x = getparent(i);
            if (x != i)
            {
                for (int j = i; j >= x; j--)
                    vis[j] = 1;
            }
            continue;
        }
        int x = getparent(i);
        if (x == i)
            ans++;
        else
        {
            for (int j = i; j >= x; j--)
                vis[j] = 1;
            ans++;
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        setunion(x, y);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}