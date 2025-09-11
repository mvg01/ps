#include <bits/stdc++.h>
using namespace std;

int mat[11][11], ans = 26;
int use[5] = {5, 5, 5, 5, 5};

bool chk(int y, int x, int r)
{
    for (int i = y; i < y + r; i++)
    {
        for (int j = x; j < x + r; j++)
        {
            if (i > 9 || j > 9)
                return 0;
            if (mat[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

void bt(int p, int cnt)
{
    if (p == 100)
    {
        ans = min(ans, cnt);
        return;
    }
    int y = p / 10;
    int x = p % 10;
    if (cnt >= ans)
        return;
    if (mat[y][x] == 1)
    {
        for (int i = 4; i >= 0; i--)
        {
            if (use[i] - 1 >= 0 && chk(y, x, i + 1))
            {
                use[i]--;
                for (int j = y; j < y + i + 1; j++)
                {
                    for (int k = x; k < x + i + 1; k++)
                        mat[j][k] = 0;
                }
                bt(p + 1, cnt + 1);
                use[i]++;
                for (int j = y; j < y + i + 1; j++)
                {
                    for (int k = x; k < x + i + 1; k++)
                        mat[j][k] = 1;
                }
            }
        }
    }
    else
    {
        bt(p + 1, cnt);
    }
}

void solve()
{
    bt(0, 0);
    if (ans == 26)
        ans = -1;
    cout << ans;
}

void input()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
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