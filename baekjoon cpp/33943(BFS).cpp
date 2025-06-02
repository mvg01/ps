#include <bits/stdc++.h>
using namespace std;

int n, m, p[2001], c = 0;
bool vis[20001];

void solve()
{
    m += 10000;
    queue<pair<int, int>> q;
    vis[10000] = 0;
    q.push({10000, 0});
    while (q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == m)
        {
            cout << y;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (x + p[i] > 20000 || x + p[i] < 0)
                continue;
            if (vis[x + p[i]])
                continue;
            q.push({x + p[i], y + 1});
            vis[x + p[i]] = 1;
        }
    }
    cout << -1;
}

void input()
{
    cin >> n >> m;
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