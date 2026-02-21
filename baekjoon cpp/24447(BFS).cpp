#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<int> v[100001];
bool vis[100001];
long long ans;

void solve()
{
    queue<pair<int, int>> q;
    q.push({r, 0});
    vis[r] = 1;
    int idx = 2;
    while (q.size())
    {
        int x = q.front().first;
        int d = q.front().second;
        q.pop();
        for (int i : v[x])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push({i, d + 1});
                ans += (long long)idx * (d + 1);
                idx++;
            }
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m >> r;
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