#include <bits/stdc++.h>
using namespace std;

int n, ans;
int mat[501][501], dp[501][501];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int y, int x)
{
    if (dp[y][x])
        return dp[y][x];
    dp[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + d[i][0];
        int xx = x + d[i][1];
        if (yy >= n || yy < 0 || xx >= n || xx < 0)
            continue;
        if (mat[y][x] < mat[yy][xx])
            dp[y][x] = max(dp[y][x], dfs(yy, xx) + 1);
    }
    return dp[y][x];
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
}

void input()
{
    cin >> n;
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