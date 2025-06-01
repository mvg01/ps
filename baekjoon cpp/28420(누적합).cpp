#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, ans = 1e9;
int mat[305][305], sum[305][305];

int f(int y1, int x1, int y2, int x2) // (y1,x1) (y2,x2) 범위 수의 합
{
    return sum[y1][x1] - sum[y1][x2] - sum[y2][x1] + sum[y2][x2];
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = a; i <= n; i++)
    {
        for (int j = b + c; j <= m; j++)
        {
            int t = f(i, j, i - a, j - b - c);
            ans = min(ans, t);
        }
    }
    for (int i = a + b; i <= n; i++)
    {
        for (int j = c + a; j <= m; j++)
        {
            int t1 = f(i - b, j - a, i - a - b, j - c - a);
            int t2 = f(i, j, i - b, j - a);
            ans = min(ans, t1 + t2);
        }
    }
    for (int i = a + c; i <= n; i++)
    {
        for (int j = a + b; j <= m; j++)
        {
            int t1 = f(i - c, j - a, i - a - c, j - a - b);
            int t2 = f(i, j, i - c, j - a);
            ans = min(ans, t1 + t2);
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m >> a >> b >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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