#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v[100001];

pair<int, int> bfs(int node, int close)
{
    vector<bool> vis(n + 1, 0);
    if (close != -1)
        vis[close] = 1;
    int mx = -1, ans = 0;
    queue<pair<int, int>> q;
    q.push({node, 0});
    vis[node] = 1;
    while (q.size())
    {
        int x = q.front().first;
        int sum = q.front().second;
        q.pop();
        if (mx < sum)
        {
            ans = x;
            mx = sum;
        }
        for (auto i : v[x])
        {
            if (vis[i.first])
                continue;
            q.push({i.first, sum + i.second});
            vis[i.first] = 1;
        }
    }
    return {ans, mx};
}

void solve()
{
    int s = bfs(1, -1).first;
    int e = bfs(s, -1).first;
    cout << max(bfs(e, s).second, bfs(s, e).second);
}

void input()
{
    cin >> n;
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