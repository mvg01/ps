#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[2001];
int vis[2001];

void solve()
{
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() && !vis[i])
        {
            q.push({i, 1});
            vis[i] = 1;
            while (q.size())
            {
                int x = q.front().first;
                int idx = q.front().second;
                q.pop();
                for (int i = 0; i < v[x].size(); i++)
                {
                    if (vis[v[x][i]] == idx)
                    {
                        cout << 0;
                        return;
                    }
                    if (vis[v[x][i]])
                        continue;
                    if (idx == 1)
                    {
                        q.push({v[x][i], 2});
                        vis[v[x][i]] = 2;
                    }
                    else
                    {
                        q.push({v[x][i], 1});
                        vis[v[x][i]] = 1;
                    }
                }
            }
        }
    }
    cout << 1;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}