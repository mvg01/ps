#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int k, n, m, A, B;
int dis[2001][201];
vector<tuple<int, int, int>> v[2001];

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            dis[i][j] = INF;
    }
    priority_queue<tuple<int, int, int>> q;
    q.push({0, A, k});
    dis[A][k] = 0;
    while (q.size())
    {
        int d = -get<0>(q.top());
        int cur = get<1>(q.top());
        int kk = get<2>(q.top());
        q.pop();
        if (dis[cur][kk] < d)
            continue;
        for (auto i : v[cur])
        {
            int nxt = get<0>(i);
            int cost = get<1>(i);
            int cut = get<2>(i);
            if (kk - cut <= 0)
                continue;
            if (dis[nxt][kk - cut] >= d + cost)
            {
                dis[nxt][kk - cut] = d + cost;
                q.push({-dis[nxt][kk - cut], nxt, kk - cut});
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= k; i++)
    {
        if (dis[B][i] != INF)
            ans = min(ans, dis[B][i]);
    }
    if (ans == INF)
        ans = -1;
    cout << ans;
}

void input()
{
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        v[a].push_back({b, t, h});
        v[b].push_back({a, t, h});
    }
    cin >> A >> B;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}