#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<int> v[200001];
bool vis[200001];

int bfs(int s)
{
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    int cnt = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto i : v[x])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int cnt = bfs(i);
            ans = max(ans, cnt);
        }
    }
    cout << ans;
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