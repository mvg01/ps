#include <bits/stdc++.h>
using namespace std;

int n, m, mat[501][501];

void solve()
{
    if (n % 2 == 1 && m % 2 == 1)
    {
        cout << "No";
        return;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j += 2)
        {
            if (j != 0)
                cout << ' ';
            cout << mat[i][j + 1] << ' ' << mat[i][j];
        }
        if (m % 2)
        {
            if (i % 2)
                cout << ' ' << mat[i - 1][m - 1] << '\n';
            else
                cout << ' ' << mat[i + 1][m - 1] << '\n';
        }
        else
            cout << '\n';
    }
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