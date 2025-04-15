#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, ans = 1e9;
vector<pair<int, int>> v[11];
bool vis[10001][11];

void solve()
{
    queue<tuple<int, int, int>> q;
    q.push({a, 0, c});
    vis[c][a] = 1;
    while (q.size())
    {
        int p = get<0>(q.front());
        int y = get<1>(q.front());
        int k = get<2>(q.front());
        q.pop();
        if (p == b)
        {
            ans = min(ans, y);
            continue;
        }
        for (auto i : v[p])
        {
            if (k - i.second >= 0)
            {
                if (!vis[k - i.second][i.first])
                {
                    vis[k - i.second][i.first] = 1;
                    q.push({i.first, max(y, i.second), k - i.second});
                }
            }
        }
    }
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}

void input()
{
    cin >> n >> m >> a >> b >> c;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}