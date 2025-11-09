#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> v[100001];
map<pair<int, int>, bool> m;
map<pair<int, int>, int> edge;
int dp[100001], ans[100001];

void dfs(int x, int par)
{
    for (int i : v[x])
    {
        if (i != par)
        {
            if (m[{x, i}] != 1)
                cnt++;
            dfs(i, x);
        }
    }
}

void dfs2(int x, int par)
{
    for (int i : v[x])
    {
        if (i != par)
        {
            if (m[{i, x}] == 1)
                dp[i] = dp[x] - 1;
            else
                dp[i] = dp[x] + 1;
            dfs2(i, x);
        }
    }
}

void dfs3(int x, int par)
{
    for (int i : v[x])
    {
        if (i != par)
        {
            if (m[{x, i}] == 1)
                ans[edge[{x, i}]] = 0;
            else
                ans[edge[{i, x}]] = 1;
            dfs3(i, x);
        }
    }
}

void solve()
{
    dfs(1, 0);
    dp[1] = cnt;
    dfs2(1, 0);
    int mn = 1e6, start;
    for (int i = 1; i <= n; i++)
    {
        if (mn > dp[i])
        {
            mn = dp[i];
            start = i;
        }
    }
    dfs3(start, 0);
    for (int i = 0; i < n - 1; i++)
        cout << ans[i];
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
        m.insert({{a, b}, 1});
        edge.insert({{a, b}, i});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}