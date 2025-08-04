#include <bits/stdc++.h>
using namespace std;

// O(N) Query

int t, n, x, y;
int par[10001], vis[10001], root[10001];
vector<int> v[10001];

void init()
{
    for (int i = 0; i < 10001; i++)
    {
        v[i].clear();
        par[i] = -1;
        vis[i] = 0;
        root[i] = 0;
    }
}

void dfs(int x, int d)
{
    vis[x] = d;
    for (auto i : v[x])
    {
        if (!vis[i])
        {
            par[i] = x;
            dfs(i, d + 1);
        }
    }
}

void solve()
{
    int start = 0;
    for (int i = 1; i <= n; i++) // 루트노드를 구해야함
    {
        if (root[i] == 0)
        {
            start = i;
            break;
        }
    }
    dfs(start, 0);
    while (x != y)
    {
        if (vis[x] < vis[y])
            swap(x, y);
        x = par[x];
    }
    cout << x << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        init();
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            root[b] = 1;
        }
        cin >> x >> y;
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}