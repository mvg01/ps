#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, p[100001];
bool vis[1000001];
void prime()
{
    for (int i = 1; i < 100001; i++)
        p[i] = i;
    for (int i = 2; i < sqrt(100001); i++)
    {
        if (p[i] == 0)
            continue;
        for (int j = i * 2; j < 100001; j += i)
            p[j] = 0;
    }
}

void solve()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    vis[n] = 1;
    while (q.size())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (x >= a && x <= b)
        {
            if (p[x] != 0)
            {
                cout << cnt << '\n';
                return;
            }
        }
        if (!vis[x / 2])
        {
            vis[x / 2] = 1;
            q.push({x / 2, cnt + 1});
        }
        if (!vis[x / 3])
        {
            vis[x / 3] = 1;
            q.push({x / 3, cnt + 1});
        }
        if (x + 1 <= 1000000 && !vis[x + 1])
        {
            vis[x + 1] = 1;
            q.push({x + 1, cnt + 1});
        }
        if (x - 1 >= 2 && !vis[x - 1])
        {
            vis[x - 1] = 1;
            q.push({x - 1, cnt + 1});
        }
    }
    cout << -1 << '\n';
}

void input()
{
    cin >> t;
    prime();
    while (t--)
    {
        cin >> n >> a >> b;
        solve();
        for (int i = 0; i < 1000001; i++)
            vis[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}