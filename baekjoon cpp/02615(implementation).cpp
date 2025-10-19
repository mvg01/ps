#include <bits/stdc++.h>
using namespace std;

int mat[20][20];
void solve()
{
    int sy, sx, resy, resx, player, cur = -1, cnt = 0;
    bool end = 0;
    for (int i = 0; i < 19; i++)
    {
        cnt = 0;
        cur = -1;
        for (int j = 0; j < 19; j++)
        {
            if (mat[i][j] == 0)
            {
                cur = -1;
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
            }
            else if ((cur == -1 && mat[i][j] != 0) || (cur != -1 && cur != mat[i][j]))
            {
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
                cur = mat[i][j];
                cnt = 1;
                sy = i;
                sx = j;
            }
            else if (cur == mat[i][j])
            {
                cnt++;
                if (cnt == 5)
                {
                    end = 1;
                    player = cur;
                    resy = sy;
                    resx = sx;
                }
                if (cnt == 6)
                    end = 0;
            }
        }
    }
    for (int i = 0; i < 19; i++)
    {
        cnt = 0;
        cur = -1;
        for (int j = 0; j < 19; j++)
        {
            if (mat[j][i] == 0)
            {
                cur = -1;
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
            }
            else if ((cur == -1 && mat[j][i] != 0) || (cur != -1 && cur != mat[j][i]))
            {
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
                cur = mat[j][i];
                cnt = 1;
                sy = j;
                sx = i;
            }
            else if (cur == mat[j][i])
            {
                cnt++;
                if (cnt == 5)
                {
                    end = 1;
                    player = cur;
                    resy = sy;
                    resx = sx;
                }
                if (cnt == 6)
                    end = 0;
            }
        }
    }

    // \ 우측 대각선
    for (int i = 0; i < 19; i++)
    {
        cnt = 0;
        cur = -1;
        for (int j = 0; j < 19; j++)
        {
            if (i + j >= 19)
                continue;
            if (mat[i + j][j] == 0)
            {
                cur = -1;
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
            }
            else if ((cur == -1 && mat[i + j][j] != 0) || (cur != -1 && cur != mat[i + j][j]))
            {
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
                cur = mat[i + j][j];
                cnt = 1;
                sy = i + j;
                sx = j;
            }
            else if (cur == mat[i + j][j])
            {
                cnt++;
                if (cnt == 5)
                {
                    end = 1;
                    player = cur;
                    resy = sy;
                    resx = sx;
                }
                if (cnt == 6)
                    end = 0;
            }
        }
    }
    for (int i = 0; i < 19; i++)
    {
        cnt = 0;
        cur = -1;
        for (int j = 0; j < 19; j++)
        {
            if (i + j >= 19)
                continue;
            if (mat[j][i + j] == 0)
            {
                cur = -1;
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
            }
            else if ((cur == -1 && mat[j][i + j] != 0) || (cur != -1 && cur != mat[j][i + j]))
            {
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
                cur = mat[j][i + j];
                cnt = 1;
                sy = j;
                sx = i + j;
            }
            else if (cur == mat[j][i + j])
            {
                cnt++;
                if (cnt == 5)
                {
                    end = 1;
                    player = cur;
                    resy = sy;
                    resx = sx;
                }
                if (cnt == 6)
                    end = 0;
            }
        }
    }

    // / 좌측 대각선
    for (int i = 0; i < 19; i++)
    {
        cnt = 0;
        cur = -1;
        for (int j = 18; j >= 0; j--)
        {
            if (i + j >= 19)
                continue;
            if (mat[18 - j][i + j] == 0)
            {
                cur = -1;
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
            }
            else if ((cur == -1 && mat[18 - j][i + j] != 0) || (cur != -1 && cur != mat[18 - j][i + j]))
            {
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
                cur = mat[18 - j][i + j];
                cnt = 1;
            }
            else if (cur == mat[18 - j][i + j])
            {
                cnt++;
                if (cnt == 5)
                {
                    end = 1;
                    player = cur;
                    resy = 18 - j;
                    resx = i + j;
                }
                if (cnt == 6)
                    end = 0;
            }
        }
    }
    for (int i = 0; i < 19; i++)
    {
        cnt = 0;
        cur = -1;
        for (int j = 18; j >= 0; j--)
        {
            if (j - i < 0)
                continue;
            if (mat[18 - j][j - i] == 0)
            {
                cur = -1;
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
            }
            else if ((cur == -1 && mat[18 - j][j - i] != 0) || (cur != -1 && cur != mat[18 - j][j - i]))
            {
                if (end)
                {
                    cout << player << '\n'
                         << resy + 1 << ' ' << resx + 1;
                    return;
                }
                cur = mat[18 - j][j - i];
                cnt = 1;
            }
            else if (cur == mat[18 - j][j - i])
            {
                cnt++;
                if (cnt == 5)
                {
                    end = 1;
                    player = cur;
                    resy = 18 - j;
                    resx = j - i;
                }
                if (cnt == 6)
                    end = 0;
            }
        }
    }
    cout << 0;
}

void input()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
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