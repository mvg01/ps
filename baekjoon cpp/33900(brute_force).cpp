#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, ans = 0;
int mat[1001][1001], t[10][10];
void solve()
{
    for (int i = 0; i <= n - r; i++)
    {
        for (int j = 0; j <= m - c; j++)
        {
            int temp = mat[i][j] - t[0][0];
            bool no = 0;
            for (int a = 0; a < r; a++)
            {
                for (int b = 0; b < c; b++)
                {
                    if (temp != mat[i + a][j + b] - t[a][b])
                    {
                        no = 1;
                        break;
                    }
                }
            }
            if (!no)
                ans++;
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> t[i][j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}