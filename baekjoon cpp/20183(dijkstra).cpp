#include <bits/stdc++.h>
#define INF 1e18
using namespace std;
using ll = long long;

int n, m, s, e, mx;
ll c;
vector<pair<int, ll>> v[100001];
ll dis[100001];

ll dijkstra(int mid)
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    priority_queue<pair<ll, int>> q;
    q.push({0, s});
    dis[s] = 0;
    while (q.size())
    {
        ll d = -q.top().first;
        int x = q.top().second;
        q.pop();
        if (dis[x] < d)
            continue;
        for (auto i : v[x])
        {
            int nxt = i.first;
            ll cost = i.second;
            if (cost > mid)
                continue;
            if (dis[nxt] > cost + d && cost + d <= c)
            {
                dis[nxt] = cost + d;
                q.push({-dis[nxt], nxt});
            }
        }
    }
    if (dis[e] == INF)
        dis[e] = -1;
    return dis[e];
}

void solve()
{
    int l = 1, r = mx, mid;
    ll ans = INF;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll result = dijkstra(mid);
        if (result == -1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
            ans = min(ans, (ll)mid);
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans;
}

void input()
{
    cin >> n >> m >> s >> e >> c;
    for (int i = 0; i < m; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        mx = max(mx, p);
        v[a].push_back({b, p});
        v[b].push_back({a, p});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}