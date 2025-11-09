#include <bits/stdc++.h>
using namespace std;

int t, n, m;
char mat[105][105];

void solve()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.')
            {
                bool chk = 0;
                for (int a = i; a < i + 3; a++)
                {
                    for (int b = j; b < j + 3; b++)
                    {
                        if (mat[a][b] == 'x' || a >= n || b >= m)
                            chk = 1;
                    }
                }
                if (chk)
                    cnt++;
                else
                {
                    for (int a = i; a < i + 3; a++)
                    {
                        for (int b = j; b < j + 3; b++)
                        {
                            mat[a][b] = 'x';
                        }
                    }
                    cnt++;
                }
            }
        }
    }
    if (cnt % 2 == 1)
        cout << "sewon\n";
    else
        cout << "pizza\n";
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> mat[i];
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}