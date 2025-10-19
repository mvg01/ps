#include <bits/stdc++.h>
using namespace std;

int n;
char mat[35][35];

bool chk(int y, int x, char p)
{
    if (p == '.')
        return 0;
    if (mat[y + 1][x + 1] == p && mat[y + 2][x + 2] == p)
        return 1;
    if (mat[y][x + 1] == p && mat[y][x + 2] == p)
        return 1;
    if (mat[y + 1][x] == p && mat[y + 2][x] == p)
        return 1;
    if (x >= 2)
    {
        if (mat[y + 1][x - 1] == p && mat[y + 2][x - 2] == p)
            return 1;
    }
    return 0;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (chk(i, j, mat[i][j]))
            {
                cout << mat[i][j];
                return;
            }
        }
    }
    cout << "ongoing";
}

void input()
{
    cin >> n;
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