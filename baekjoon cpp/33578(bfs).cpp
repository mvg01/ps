#include <bits/stdc++.h>
using namespace std;

int n, m, sy, sx, ey, ex, ans = 1e9;
char mat[3001][3001];
int vis[3001][3001][2];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve()
{
    queue<tuple<int, int, int, bool>> q;
    q.push({sy, sx, 0, false});
    vis[sy][sx][0] = 1;
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        bool jinwoo = get<3>(q.front());
        q.pop();
        if (vis[y][x][jinwoo] < t)
            continue;
        if (y == ey && x == ex)
        {
            ans = min(ans, t);
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (mat[yy][xx] == '#')
                continue;
            if (!jinwoo)
            {
                if (mat[yy][xx] == 'T')
                {
                    if (vis[yy][xx][1] <= t + 2)
                        continue;
                    q.push({yy, xx, t + 2, true});
                    vis[yy][xx][1] = t + 2;
                }
                if (vis[yy][xx][0] <= t + 2)
                    continue;
                q.push({yy, xx, t + 2, false});
                vis[yy][xx][0] = t + 2;
            }
            else
            {
                if (vis[yy][xx][1] <= t + 1)
                    continue;
                q.push({yy, xx, t + 1, true});
                vis[yy][xx][1] = t + 1;
            }
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'J')
            {
                sy = i;
                sx = j;
            }
            else if (mat[i][j] == 'S')
            {
                ey = i;
                ex = j;
            }
            vis[i][j][0] = 1e9;
            vis[i][j][1] = 1e9;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}