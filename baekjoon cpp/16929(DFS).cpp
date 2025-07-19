#include <bits/stdc++.h>
using namespace std;

int n, m;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char mat[51][51];
bool vis[51][51];

void dfs(int y, int x, int fy, int fx, int d)
{
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dir[i][0];
        int xx = x + dir[i][1];
        if (yy >= n || yy < 0 || xx >= m || xx < 0)
            continue;
        if (mat[yy][xx] == mat[y][x])
        {
            if (!vis[yy][xx])
            {
                vis[yy][xx] = 1;
                dfs(yy, xx, fy, fx, d + 1);
            }
            else if (d >= 3 && yy == fy && xx == fx)
            { // 싸이클 존재
                // cout << yy << ' ' << xx << ' ';   // 싸이클 시작 좌표
                cout << "Yes";
                exit(0);
            }
        }
    }
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
            init();
            vis[i][j] = 1;
            dfs(i, j, i, j, 0);
        }
    }
    cout << "No";
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