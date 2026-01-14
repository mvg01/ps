#include <bits/stdc++.h>
using namespace std;

int n, m, sy, sx;
int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
string p[4] = {"lijevo", "desno", "dolje", "gore"};
char mat[11][11];
bool vis[11][11];

void solve()
{
    queue<pair<int, int>> q;
    q.push({sy, sx});
    vis[sy][sx] = 1;
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis[yy][xx])
                continue;
            if (mat[yy][xx] == 'x')
            {
                cout << p[i] << '\n';
                q.push({yy, xx});
                vis[yy][xx] = 1;
            }
        }
    }
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'P')
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