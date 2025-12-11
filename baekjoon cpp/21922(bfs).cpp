#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int mat[2001][2001];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool vis[2001][2001][4];
queue<tuple<int, int, int>> q;

void solve()
{
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dir = get<2>(q.front());
        q.pop();
        ans++;
        int yy = y + d[dir][0];
        int xx = x + d[dir][1];
        if (yy >= n || yy < 0 || xx >= m || xx < 0)
            continue;
        if (vis[yy][xx][dir])
            continue;
        int p = mat[yy][xx];
        if (p == 0)
        {
            q.push({yy, xx, dir});
            vis[yy][xx][dir] = 1;
        }
        if (p == 1)
        {
            if (dir == 0 || dir == 2)
            {
                q.push({yy, xx, dir});
                vis[yy][xx][dir] = 1;
            }
        }
        if (p == 2)
        {
            if (dir == 1 || dir == 3)
            {
                q.push({yy, xx, dir});
                vis[yy][xx][dir] = 1;
            }
        }
        if (p == 3)
        {
            if (dir == 0)
            {
                q.push({yy, xx, 1});
                vis[yy][xx][1] = 1;
            }
            else if (dir == 1)
            {
                q.push({yy, xx, 0});
                vis[yy][xx][0] = 1;
            }
            else if (dir == 2)
            {
                q.push({yy, xx, 3});
                vis[yy][xx][3] = 1;
            }
            else
            {
                q.push({yy, xx, 2});
                vis[yy][xx][2] = 1;
            }
        }
        if (p == 4)
        {
            if (dir == 0)
            {
                q.push({yy, xx, 3});
                vis[yy][xx][3] = 1;
            }
            else if (dir == 1)
            {
                q.push({yy, xx, 2});
                vis[yy][xx][2] = 1;
            }
            else if (dir == 2)
            {
                q.push({yy, xx, 1});
                vis[yy][xx][1] = 1;
            }
            else
            {
                q.push({yy, xx, 0});
                vis[yy][xx][0] = 1;
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
        {
            cin >> mat[i][j];
            if (mat[i][j] == 9)
            {
                for (int k = 0; k < 4; k++)
                {
                    q.push({i, j, k});
                    vis[i][j][k] = 1;
                }
            }
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