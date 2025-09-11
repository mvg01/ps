#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int d[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
char mat[101][101];
int vis[101][101];
vector<tuple<int, int, int>> v;

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    vis[y][x] = 1;
    q.push({y, x});
    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (!vis[yy][xx] && mat[yy][xx] != '0')
            {
                q.push({yy, xx});
                vis[yy][xx] = 1;
            }
        }
    }
}

void f()
{
    sort(v.begin(), v.end());
    for (auto k : v)
    {
        int p = get<0>(k);
        int y = get<1>(k);
        int x = get<2>(k);
        for (int i = max(0, y - p); i <= min(n - 1, y + p); i++)
        {
            for (int j = max(0, x - p); j <= min(m - 1, x + p); j++)
            {
                mat[i][j] = p + '0';
            }
        }
    }
}

void init()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
            vis[i][j] = 0;
    }
    v.clear();
}

void solve()
{
    while (1)
    {
        init();
        bool chk = 0, go = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != '0' && !vis[i][j])
                {
                    if (chk)
                    {
                        go = 1; // 한 덩어리가 아님
                        break;
                    }
                    bfs(i, j);
                    chk = 1;
                }
            }
            if (go)
                break;
        }
        if (!go && chk)
        {
            cout << ans;
            return;
        }
        ans++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != '0')
                {
                    v.push_back({mat[i][j] - '0', i, j});
                }
            }
        }
        f();
    }
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}