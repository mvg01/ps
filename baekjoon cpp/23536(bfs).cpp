#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int h, w, sy, sx, dis[501][501];
int dir[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
char mat[501][501];

bool wall(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dir[i][0];
        int xx = x + dir[i][1];
        if (yy >= h || yy < 0 || xx >= w || xx < 0)
            continue;
        if (mat[yy][xx] == '#')
            return 1;
    }
    return 0;
}

void solve()
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            dis[i][j] = INF;

    // 0-1 bfs
    deque<tuple<int, int, int>> d;
    d.push_back({sy, sx, 0});
    dis[sy][sx] = 0;
    while (d.size())
    {
        int y = get<0>(d.front());
        int x = get<1>(d.front());
        int t = get<2>(d.front());
        d.pop_front();
        if (t != dis[y][x])
            continue; // 무효한 경로
        // cout << y << ' ' << x << ' ' << t << '\n';
        if (mat[y][x] == 'E')
        {
            cout << t;
            return;
        }
        bool chk = wall(y, x);
        for (int i = 0; i < 4; i++)
        {
            int yy = y + dir[i][0];
            int xx = x + dir[i][1];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (mat[yy][xx] == '#')
                continue;
            int wcost = 1; // 벽 이동 비용
            if (chk && wall(yy, xx))
                wcost = 0; // 둘 다 벽 인접이면 순식간에 벽 이동
            if (t + wcost >= dis[yy][xx])
                continue;

            dis[yy][xx] = t + wcost;
            if (wcost == 0)
                d.push_front({yy, xx, t});
            else
                d.push_back({yy, xx, t + 1});
        }
    }
}

void input()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == 'S')
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