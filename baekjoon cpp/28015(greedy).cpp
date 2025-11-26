#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int mat[101][101];
bool vis[101][101];

void color(int y, int x, int c)
{
    vis[y][x] = 1;
    bool chk = 0, chk2 = 0;
    for (int i = x + 1; i < m; i++)
    {
        if (mat[y][i] == c)
        {
            vis[y][i] = 1;
            if (chk)
                chk2 = 1;
        }
        else if (mat[y][i] == 0)
            break;
        else
        {
            if (vis[y][i])
                break;
            if (!chk)
            {
                ans++;
                chk = 1;
            }
            if (!chk2)
                vis[y][i] = 1;
        }
    }
    ans++;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                if (mat[i][j] == 1)
                    color(i, j, 1);
                if (mat[i][j] == 2)
                    color(i, j, 2);
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