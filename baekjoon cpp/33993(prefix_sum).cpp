#include <bits/stdc++.h>
using namespace std;

int n, r, c, w;
int mat[5001][5001], sum[5001][5001];

void solve()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++) // 2차원 배열 누적합
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
    int mn = 0, y, x, half = w / 2;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (mat[i][j]) // 친구자리
                continue;
            int di = min(i + half, r);
            int dj = min(j + half, c);
            int ui = max(i - half, 1);
            int uj = max(j - half, 1);
            int t = sum[di][dj] - sum[ui - 1][dj] - sum[di][uj - 1] + sum[ui - 1][uj - 1];
            if (mn < t)
            {
                mn = t;
                y = i;
                x = j;
            }
        }
    }
    cout << mn << '\n'
         << y << ' ' << x;
}

void input()
{
    cin >> n >> r >> c >> w;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}