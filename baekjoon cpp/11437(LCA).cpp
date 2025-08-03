#include <bits/stdc++.h>
using namespace std;

// O(N) LCA query

int n, m, d[50001], par[50001];
bool vis[50001];
vector<int> v[50001];

void dfs(int x, int depth)
{
    vis[x] = 1;
    d[x] = depth;
    for (auto i : v[x])
    {
        if (!vis[i])
        {
            par[i] = x; // i의 부모는 x
            dfs(i, depth + 1);
        }
    }
}

void solve()
{
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (d[a] < d[b])
            swap(a, b);
        while (d[a] != d[b])
            a = par[a];
        if (a == b)
        {
            cout << a << '\n';
            continue;
        }
        while (par[a] != par[b])
        {
            a = par[a];
            b = par[b];
        }
        cout << par[a] << '\n';
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}