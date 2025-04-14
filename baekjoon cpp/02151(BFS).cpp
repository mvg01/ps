#include <bits/stdc++.h>
using namespace std;

int n, sy, sx;
char mat[51][51];
bool vis[51][51][4];
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 오른, 왼, 위, 아래

void solve()
{
    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < 4; i++)
    {
        q.push({sy, sx, i, 0});
        vis[sy][sx][i] = 1;
    }
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dir = get<2>(q.front());
        int c = get<3>(q.front());
        q.pop();
        while (1)
        {
            int yy = y + d[dir][0];
            int xx = x + d[dir][1];
            if (yy >= n || xx >= n || yy < 0 || xx < 0)
                break;
            if (vis[yy][xx][dir])
                break;
            if (mat[yy][xx] == '*')
                break;
            if (mat[yy][xx] == '!')
            {
                if (dir == 0 || dir == 1)
                {
                    if (!vis[yy][xx][2])
                    {
                        q.push({yy, xx, 2, c + 1});
                        vis[yy][xx][2] = 1;
                    }
                    if (!vis[yy][xx][3])
                    {
                        q.push({yy, xx, 3, c + 1});
                        vis[yy][xx][3] = 1;
                    }
                }
                else
                {
                    if (!vis[yy][xx][0])
                    {
                        q.push({yy, xx, 0, c + 1});
                        vis[yy][xx][0] = 1;
                    }
                    if (!vis[yy][xx][1])
                    {
                        q.push({yy, xx, 1, c + 1});
                        vis[yy][xx][1] = 1;
                    }
                }
            }
            if (mat[yy][xx] == '#')
            {
                cout << c;
                return;
            }
            vis[yy][xx][dir] = 1;
            y = yy;
            x = xx;
        }
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == '#')
            {
                sy = i;
                sx = j;
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