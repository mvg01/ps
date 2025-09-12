#include <bits/stdc++.h>
using namespace std;

int n, m, mat[21][21], ans;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[21][21];

int bfs(int y, int x)
{
    int cnt = 1;
    bool chk = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    vis[y][x] = 1;
    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy < 0 || yy >= n || xx < 0 || xx >= m)
                continue;
            if (vis[yy][xx])
                continue;
            if (mat[yy][xx] == 2)
            {
                q.push({yy, xx});
                vis[yy][xx] = 1;
                cnt++;
            }
            else if (mat[yy][xx] == 0)
            {
                chk = 1;
            }
        }
    }
    if (chk)
        cnt = 0;
    return cnt;
}

void query(int y, int x, int y2, int x2)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + d[i][0];
        int xx = x + d[i][1];
        if (yy < 0 || yy >= n || xx < 0 || xx >= m)
            continue;
        if (!vis[yy][xx] && mat[yy][xx] == 2)
        {
            cnt += bfs(yy, xx);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int yy = y2 + d[i][0];
        int xx = x2 + d[i][1];
        if (yy < 0 || yy >= n || xx < 0 || xx >= m)
            continue;
        if (!vis[yy][xx] && mat[yy][xx] == 2)
        {
            cnt += bfs(yy, xx);
        }
    }
    ans = max(ans, cnt);
}

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            vis[i][j] = 0;
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = i; k < n; k++)
                {
                    for (int l = 0; l < m; l++)
                    {
                        if (k == i && l == j)
                            continue;
                        if (mat[k][l] == 0)
                        {
                            mat[i][j] = 1;
                            mat[k][l] = 1;
                            // cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
                            init();
                            query(i, j, k, l);
                            mat[i][j] = 0;
                            mat[k][l] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}