#include <bits/stdc++.h>
using namespace std;

int n, m, mat[501][501];
int d[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
bool vis[501][501][2][11];

void solve()
{
    queue<tuple<int, int, int, int, bool>> q; // y,x,움직임,날,낮or밤
    q.push({0, 0, 0, 1, 0});
    vis[0][0][0][0] = 1;
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int move = get<2>(q.front());
        int day = get<3>(q.front());
        bool c = get<4>(q.front());
        q.pop();
        if (y == n - 1 && x == n - 1)
        {
            cout << day << (c ? " moon" : " sun");
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= n || xx < 0)
                continue;
            if (c)
            {
                if (mat[yy][xx] == 0)
                {
                    if (move + 1 == m)
                    {
                        if (vis[yy][xx][!c][0])
                            continue;
                        q.push({yy, xx, 0, (c ? day + 1 : day), !c});
                        vis[yy][xx][!c][0] = 1;
                    }
                    else
                    {
                        if (vis[yy][xx][c][move + 1])
                            continue;
                        q.push({yy, xx, move + 1, day, c});
                        vis[yy][xx][c][move + 1] = 1;
                    }
                }
                else
                {
                    int dy = yy + d[i][0];
                    int dx = xx + d[i][1];
                    while (1)
                    {
                        if (dy >= n || dy < 0 || dx >= n || dx < 0)
                            break;
                        if (mat[dy][dx] == 0)
                        {
                            if (move + 1 == m)
                            {
                                if (vis[dy][dx][!c][0])
                                    break;
                                q.push({dy, dx, 0, (c ? day + 1 : day), !c});
                                vis[dy][dx][!c][0] = 1;
                            }
                            else
                            {
                                if (vis[dy][dx][i][move + 1])
                                    break;
                                q.push({dy, dx, move + 1, day, c});
                                vis[dy][dx][c][move + 1] = 1;
                            }
                            break;
                        }
                        dy += d[i][0];
                        dx += d[i][1];
                    }
                }
            }
            else
            {
                if (mat[yy][xx] == 0)
                {
                    if (move + 1 == m)
                    {
                        if (vis[yy][xx][!c][0])
                            continue;
                        q.push({yy, xx, 0, (c ? day + 1 : day), !c});
                        vis[yy][xx][!c][0] = 1;
                    }
                    else
                    {
                        if (vis[yy][xx][c][move + 1])
                            continue;
                        q.push({yy, xx, move + 1, day, c});
                        vis[yy][xx][c][move + 1] = 1;
                    }
                }
            }
        }
    }
    cout << -1;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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