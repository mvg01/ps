#include <bits/stdc++.h>
#define INF 1e18
using ll = long long;
using namespace std;

int n, m, a, b;
ll mindis;
ll dis[200001], dis2[200001];
vector<pair<ll, ll>> v[200001];
priority_queue<pair<ll, ll>> pq;

void solve()
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INF;
        dis2[i] = INF;
    }
    // 출발점에서 최단경로
    pq.push({0, a});
    dis[a] = 0;
    while (pq.size())
    {
        ll d = -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
        if (d > dis[cur])
            continue;
        for (auto i : v[cur])
        {
            if (dis[i.first] > d + i.second)
            {
                pq.push({-(d + i.second), i.first});
                dis[i.first] = d + i.second;
            }
        }
    }
    mindis = dis[b];

    // 도착점에서 최단경로
    pq.push({0, b});
    dis2[b] = 0;
    while (pq.size())
    {
        ll d = -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
        if (d > dis2[cur])
            continue;
        for (auto i : v[cur])
        {
            if (dis2[i.first] > d + i.second)
            {
                pq.push({-(d + i.second), i.first});
                dis2[i.first] = d + i.second;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] + dis2[i] == mindis)
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != ans.size() - 1)
            cout << ans[i] << ' ';
        else
            cout << ans[i];
    }
}

void input()
{
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
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