#include <bits/stdc++.h>
using namespace std;

char mat[8][8];
int d[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int ey, ex;
double ans = 0;

int combi(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return combi(n - 1, r - 1) + combi(n - 1, r);
}

void solve()
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            if (mat[i][j] == 'O')
                cnt++;
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int p = 0;
            for (int k = 0; k < 4; k++)
                if (mat[i + d[k][0]][j + d[k][1]] == 'O')
                    p++;
            if (cnt - p < 4)
            {
                ans = 1;
                ey = i + 1;
                ex = j + 1;
                continue;
            }
            int x = combi(cnt, 4);
            int y = combi(cnt - p, 4);
            double per = 1 - (double(y) / double(x));
            if (per > ans)
            {
                ans = per;
                ey = i + 1;
                ex = j + 1;
            }
        }
    }
    cout << ey << ' ' << ex << '\n'
         << ans;
}

void input()
{
    for (int i = 0; i < 8; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(8);
    input();
    solve();
}