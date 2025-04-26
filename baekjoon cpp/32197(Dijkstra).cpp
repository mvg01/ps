#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, a, b;
vector<pair<int, bool>> v[100001];
int dis[100001][2];
priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;

void solve()
{
    for (int i = 0; i <= n; i++)
    {
        dis[i][0] = INF;
        dis[i][1] = INF;
    }
    dis[a][0] = 0;
    dis[a][1] = 0;
    for (auto i : v[a]) // 시작지점과 연결된 임의 역들
    {
        pq.push({0, i.first, i.second});
        dis[i.first][i.second] = 0;
    }
    while (pq.size())
    {
        int x = get<0>(pq.top());
        int cur = get<1>(pq.top());
        bool p = get<2>(pq.top());
        pq.pop();
        if (dis[cur][0] < x && dis[cur][1] < x)
            continue;
        for (auto i : v[cur])
        {
            if (i.second == p && dis[i.first][i.second] > x)
            {
                pq.push({x, i.first, p});
                dis[i.first][i.second] = x;
            }
            else if (i.second != p && dis[i.first][i.second] > x + 1)
            {
                pq.push({x + 1, i.first, i.second});
                dis[i.first][i.second] = x + 1;
            }
        }
    }
    cout << min(dis[b][0], dis[b][1]);
}

void input()
{
    cin >> n >> m;
    int s, e, t;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> t;
        v[s].push_back({e, t});
        v[e].push_back({s, t});
    }
    cin >> a >> b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}