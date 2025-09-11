#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int vis[500001];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({a, 0});
    q.push({b, 0});
    while (q.size())
    {
        int p = q.front().first;
        int d = q.front().second;
        q.pop();
        int nxt = (int)pow(2, d);
        if (p + nxt <= n)
        {
            if (vis[p + nxt] == d + 1)
            {
                cout << d + 1;
                return;
            }
            else
            {
                vis[p + nxt] = d + 1;
                q.push({p + nxt, d + 1});
            }
        }
        if (p - nxt > 0)
        {
            if (vis[p - nxt] == d + 1)
            {
                cout << d + 1;
                return;
            }
            else
            {
                vis[p - nxt] = d + 1;
                q.push({p - nxt, d + 1});
            }
        }
    }
    cout << -1;
}

void solve()
{
    bfs();
}

void input()
{
    cin >> n >> a >> b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}

// 혹은 메모리를 더 활용해서 풀 수 있다. 더 쉬운 풀이라고 생각된다.
#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int vis[500001][2][21];

void bfs(int t)
{
    queue<pair<int, int>> q;
    if (t == 0)
    {
        q.push({a, 0});
        vis[a][0][0] = 1;
    }
    else
    {
        q.push({b, 0});
        vis[b][1][0] = 1;
    }
    while (q.size())
    {
        int p = q.front().first;
        int d = q.front().second;
        q.pop();
        int nxt = (int)pow(2, d);
        if (p + nxt <= n)
        {
            if (!vis[p + nxt][t][d + 1])
            {
                q.push({p + nxt, d + 1});
                vis[p + nxt][t][d + 1] = d + 1;
            }
        }
        if (p - nxt > 0)
        {
            if (!vis[p - nxt][t][d + 1])
            {
                q.push({p - nxt, d + 1});
                vis[p - nxt][t][d + 1] = d + 1;
            }
        }
    }
}

void solve()
{
    bfs(0);
    bfs(1);
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 20; j++)
        {
            if (vis[i][0][j] == vis[i][1][j])
            {
                if (vis[i][0][j] != 0)
                {
                    ans = min(ans, vis[i][0][j]);
                    // cout << i << ' ';
                }
            }
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans;
}

void input()
{
    cin >> n >> a >> b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}