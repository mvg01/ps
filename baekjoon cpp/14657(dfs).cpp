#include <bits/stdc++.h>
using namespace std;

int n, t, max_d, min_cost = 1e9;
pair<int, int> dis[50001];
vector<pair<int, int>> v[50001];

void dfs(int x, int d, int cost)
{
    for (auto i : v[x])
    {
        if (dis[i.first].first == -1)
        {
            dis[i.first].first = d + 1;
            dis[i.first].second = cost + i.second;
            dfs(i.first, d + 1, cost + i.second);
        }
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i].first = -1;
        dis[i].second = 1e9;
    }
}

void solve()
{
    init();
    dis[1] = {0, 0};
    dfs(1, 0, 0);
    int mx_d = 0, mn_cost = 1e9, start_n = 0;
    for (int i = 2; i <= n; i++)
    {
        if (mx_d < dis[i].first)
        {
            mx_d = dis[i].first;
            mn_cost = dis[i].second;
            start_n = i;
        }
        else if (mx_d == dis[i].first && mn_cost > dis[i].second)
        {
            mn_cost = dis[i].second;
            start_n = i;
        }
    }

    init();
    dis[start_n].first = 0;
    dfs(start_n, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        // 문제를 많이 풀되 짧은 시간
        if (dis[i].first > max_d)
        {
            max_d = dis[i].first;
            min_cost = dis[i].second;
        }
        else if (dis[i].first == max_d)
            min_cost = min(min_cost, dis[i].second);
    }
    int ans = min_cost / t;
    if (min_cost % t != 0)
        ans++;
    cout << ans;
}

void input()
{
    cin >> n >> t;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}