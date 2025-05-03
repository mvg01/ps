#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int w, h, sy, sx, ey, ex, ans = INF;
char mat[501][501];
int dis[501][501];
int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void solve()
{
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, sy, sx});
    dis[sy][sx] = 0;
    while (pq.size())
    {
        int c = get<0>(pq.top());
        int y = get<1>(pq.top());
        int x = get<2>(pq.top());
        c *= -1;
        // cout << y << ' ' << x << ' ' << c << '\n';
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (mat[yy][xx] == 'R' || mat[yy][xx] == 'H')
                continue;
            if (mat[yy][xx] == 'E')
            {
                ans = min(ans, c);
                continue;
            }
            int u = c + mat[yy][xx] - '0', ty = yy, tx = xx;
            while (1)
            {
                ty = yy + d[i][0];
                tx = xx + d[i][1];
                if (ty >= h || ty < 0 || tx >= w || tx < 0)
                    break;
                if (mat[ty][tx] == 'E')
                {
                    ans = min(ans, u);
                    break;
                }
                if (mat[ty][tx] == 'H')
                    break;
                if (mat[ty][tx] == 'R')
                {
                    if (dis[yy][xx] <= u)
                        break;
                    dis[yy][xx] = u;
                    pq.push({-u, yy, xx});
                    break;
                }
                u += mat[ty][tx] - '0';
                yy = ty;
                xx = tx;
            }
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans;
}

void input()
{
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == 'T')
            {
                sy = i;
                sx = j;
                mat[i][j] = '0';
            }
            else if (mat[i][j] == 'E')
            {
                ey = i;
                ex = j;
            }
            dis[i][j] = INF;
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

// BFS 풀이도 가능 정해 풀이는 아닌듯.
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int w, h, sy, sx, ey, ex, ans = INF;
char mat[501][501];
int dis[501][501][4];
int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void solve()
{
    queue<tuple<int, int, int>> q;
    q.push({sy, sx, 0});
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int c = get<2>(q.front());
        // cout << y << ' ' << x << ' ' << c << '\n';
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (dis[y][x][i] <= c)
                continue;
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (mat[yy][xx] == 'R' || mat[yy][xx] == 'H')
                continue;
            if (mat[yy][xx] == 'E')
            {
                ans = min(ans, c);
                continue;
            }
            dis[y][x][i] = c;
            int u = c + mat[yy][xx] - '0', ty = yy, tx = xx;
            while (1)
            {
                dis[yy][xx][i] = u;
                dis[yy][xx][(i + 6) % 4] = u;
                ty = yy + d[i][0];
                tx = xx + d[i][1];
                if (ty >= h || ty < 0 || tx >= w || tx < 0)
                    break;
                if (dis[ty][tx][i] < u + mat[ty][tx] - '0')
                    break;
                if (mat[ty][tx] == 'E')
                {
                    ans = min(ans, u);
                    break;
                }
                if (mat[ty][tx] == 'H')
                    break;
                if (mat[ty][tx] == 'R')
                {
                    q.push({yy, xx, u});
                    break;
                }
                u += mat[ty][tx] - '0';
                yy = ty;
                xx = tx;
            }
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans;
}

void input()
{
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == 'T')
            {
                sy = i;
                sx = j;
                mat[i][j] = '0';
            }
            else if (mat[i][j] == 'E')
            {
                ey = i;
                ex = j;
            }
            for (int k = 0; k < 4; k++)
                dis[i][j][k] = INF;
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