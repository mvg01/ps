#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char mat[51][51];
int d1[6][2] = {{0, -1}, {1, -1}, {1, 0}, {0, 1}, {-1, 0}, {-1, -1}};
int d2[6][2] = {{0, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.')
                continue;
            if (i % 2 == 1)
            {
                for (int k = 0; k < 6; k++)
                {
                    int y = i + d2[k][0];
                    int x = j + d2[k][1];
                    if (y < 0 || y >= n || x < 0 || x >= m)
                        continue;
                    if (mat[y][x] == '.')
                        ans++;
                }
            }
            else
            {
                for (int k = 0; k < 6; k++)
                {
                    int y = i + d1[k][0];
                    int x = j + d1[k][1];
                    if (y < 0 || y >= n || x < 0 || x >= m)
                        continue;
                    if (mat[y][x] == '.')
                        ans++;
                }
            }
        }
    }
    cout << ans;
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