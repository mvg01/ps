#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
using ll = long long;

ll n, s, e, m, p[51], dis[51], vis[51];
bool loop = 0, gg = 0;
vector<pair<pair<int, int>, ll>> v;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (x == e)
        {
            cout << "Gee";
            loop = 1;
            return;
        }
        for (int i = 0; i < m; i++)
        {
            if (vis[v[i].first.second])
                continue;
            if (x == v[i].first.first)
            {
                q.push(v[i].first.second);
                vis[v[i].first.second] = 1;
            }
        }
    }
}

void check_gg()
{
    queue<int> q;
    q.push(s);
    for (int i = 0; i < 51; i++)
        vis[i] = 0;
    vis[s] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (x == e)
            return;
        for (int i = 0; i < m; i++)
        {
            if (vis[v[i].first.second])
                continue;
            if (x == v[i].first.first)
            {
                q.push(v[i].first.second);
                vis[v[i].first.second] = 1;
            }
        }
    }
    gg = 1;
}

void solve()
{
    for (int i = 0; i <= n; i++)
        dis[i] = INF;
    dis[s] = -p[s];
    for (int i = 0; i < n - 1; i++)
    { // 벨만 포드
        for (int j = 0; j < m; j++)
        {
            int start = v[j].first.first;
            int end = v[j].first.second;
            ll weight = v[j].second - p[end];
            if (dis[start] != INF)
            {
                if (dis[end] > dis[start] + weight)
                    dis[end] = dis[start] + weight;
            }
        }
    }
    for (int i = 0; i < m; i++)
    { // 음의 사이클(무한 돈) 존재 여부
        int start = v[i].first.first;
        int end = v[i].first.second;
        ll weight = v[i].second - p[end];
        if (dis[start] != INF)
        {
            if (dis[end] > dis[start] + weight)
            {
                bfs(start);
                if (loop) // 음의 사이클이 도착지를 포함한다면
                    return;
            }
        }
    }
    check_gg(); // 출발지에서 도착지 가능 여부
    if (gg)
        cout << "gg";
    else
        cout << -dis[e];
}

void input()
{
    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    for (int i = 0; i < n; i++)
        cin >> p[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}