#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[211][561];

void judge(int y, int x, bool res, int c)
{
    if (res)
    {
        int p;
        if (c > 9)
            p = 7;
        else
            p = 6;
        for (int i = x * 8 + 1; i < x * 8 + p; i++)
        {
            mat[y * 3][i] = '*';
            mat[y * 3 + 2][i] = '*';
        }
        mat[y * 3 + 1][x * 8] = '*';
        mat[y * 3 + 1][x * 8 + p] = '*';
    }
    else
    {
        mat[y * 3][x * 8 + 3] = '/';
        mat[y * 3 + 1][x * 8 + 2] = '/';
        mat[y * 3 + 2][x * 8 + 1] = '/';
    }
}

void cacl(int y, int x)
{
    int yy = y, xx = x;
    y = y * 3 + 1;
    x = x * 8 + 1;
    int a = mat[y][x] - '0';
    int b = mat[y][x + 2] - '0';
    int c = mat[y][x + 4] - '0';
    if (mat[y][x + 5] != '.')
    {
        c *= 10;
        c += mat[y][x + 5] - '0';
    }
    bool res = 0;
    if (a + b == c)
        res = 1;
    judge(yy, xx, res, c);
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cacl(i, j);
        }
    }
    for (int i = 0; i < n * 3; i++)
        cout << mat[i] << '\n';
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n * 3; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}