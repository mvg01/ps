#include <bits/stdc++.h>
using namespace std;

int r, c;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mat[11][11];

void solve()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == '.')
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int y = i + d[k][0];
                    int x = j + d[k][1];
                    if (y >= r || y < 0 || x >= c || x < 0)
                        continue;
                    if (mat[y][x] == '.')
                        cnt++;
                }
                if (cnt < 2)
                {
                    cout << 1;
                    return;
                }
            }
        }
    }
    cout << 0;
}

void input()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}