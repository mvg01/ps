#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, ans;
int d[10001];
vector<pair<int, int>> v1[10001], v2[10001];
int dis[10001];
bool vis[10001];

void topo()
{
    queue<int> q;
    q.push(s);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto i : v1[x])
        {
            d[i.first]--;
            dis[i.first] = max(dis[i.first], dis[x] + i.second);
            if (d[i.first] == 0)
                q.push(i.first);
        }
    }
}

void reverse_topo()
{
    queue<int> q;
    q.push(e);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto i : v2[x])
        {
            if (dis[i.first] + i.second == dis[x])
            {
                ans++;
                if (!vis[i.first])
                {
                    vis[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
    }
}

void solve()
{
    topo();
    reverse_topo();
    cout << dis[e] << '\n'
         << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[b]++;
        v1[a].push_back({b, c});
        v2[b].push_back({a, c});
    }
    cin >> s >> e;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}