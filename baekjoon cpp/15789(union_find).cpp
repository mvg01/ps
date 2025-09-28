#include <bits/stdc++.h>
using namespace std;

int n, m, c, h, k, ans = 1;
int par[100001], cnt[100001];
bool vis[100001];
vector<int> v[100001];

int getpar(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = getpar(par[x]);
}

void setunion(int a, int b)
{
    a = getpar(a);
    b = getpar(b);
    if (a < b)
        par[b] = a;
    else
        par[a] = b;
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto i : v[x])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
                if (start == c)
                    ans++;
            }
        }
    }
}

void solve()
{
    bfs(c);
    bfs(h);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (auto j : v[i])
        {
            if (i < j)
                setunion(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
        cnt[getpar(i)]++;
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > 0 && !vis[i])
            pq.push({cnt[i], i});
    }
    while (k--)
    {
        if (pq.empty())
            break;
        int power = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        ans += power;
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin >> c >> h >> k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}