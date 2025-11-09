#include <bits/stdc++.h>
using namespace std;

int n, m, x;
vector<int> v[100001], v2[100001];
bool vis[100001];

// x보다 잘한 학생의 수를 찾는다.
int bfs()
{
    if (v[x].size() == 0)
        return 1;
    int cnt = 0;
    queue<int> q;
    for (auto i : v[x])
    {
        q.push(i);
        vis[i] = 1;
        cnt++;
    }
    while (q.size())
    {
        int y = q.front();
        q.pop();
        for (auto i : v[y])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
                cnt++;
            }
        }
    }
    return cnt + 1;
}

// x보다 못한 학생의 수를 찾는다.
int bfs2()
{
    if (v2[x].size() == 0)
        return n;
    int cnt = 0;
    queue<int> q;
    for (auto i : v2[x])
    {
        q.push(i);
        vis[i] = 1;
        cnt++;
    }
    while (q.size())
    {
        int y = q.front();
        q.pop();
        for (auto i : v2[y])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
                cnt++;
            }
        }
    }
    return n - cnt;
}

void solve()
{
    int first = bfs();
    for (int i = 0; i <= n; i++)
        vis[i] = 0;
    int second = bfs2();
    cout << first << ' ' << second;
}

void input()
{
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        v2[a].push_back(b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}