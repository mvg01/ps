#include <bits/stdc++.h>
using namespace std;

int t, n, m, cnt = 0;
vector<int> v[300001];
int vis[300001];
bool no = 0;

void dfs(int s, int team)
{
    for (auto i : v[s])
    {
        if (!vis[i])
        {
            if (team == 1)
            {
                vis[i] = 2;
                dfs(i, 2);
                cnt++;
            }
            else
            {
                vis[i] = 1;
                dfs(i, 1);
                cnt++;
            }
        }
        else if (vis[i] == team)
            no = 1;
    }
}

void solve()
{
    while (cnt != n) // 이분그래프 풀이
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                vis[i] = 1;
                dfs(i, 1);
            }
        }
    }
    if (no || cnt != n)
        cout << "NO\n";
    else
        cout << "YES\n";
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int x, y;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        solve();
        cnt = 0;
        no = 0;
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}