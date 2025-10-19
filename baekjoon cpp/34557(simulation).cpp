#include <bits/stdc++.h>
using namespace std;

int n, m, sy, sx;
int mat[101][101];
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 상,좌,하,우
int event[4];
map<char, int> mp;
string q;

void solve()
{
    char pre = 'X';
    int y = sy, x = sx;
    mp.insert({'W', 0});
    mp.insert({'A', 1});
    mp.insert({'S', 2});
    mp.insert({'D', 3});
    for (int i = 0; i < m; i++)
    {
        int yy = y, xx = x;
        if (q[i] == 'W')
        {
            if (event[0] == 0)
            {
                if (pre != q[i])
                {
                    yy += d[0][0];
                    xx += d[0][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[0][0];
                        xx -= d[0][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[0][0];
                        xx -= d[0][1];
                    }
                }
            }
            else if (event[0] == 1)
            {
                if (pre == q[i])
                {
                    yy += d[0][0];
                    xx += d[0][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[0][0];
                        xx -= d[0][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[0][0];
                        xx -= d[0][1];
                    }
                }
            }
        }
        if (pre == 'W')
        {
            if (event[mp[pre]] == 2 && mp[pre] != mp[q[i]])
            {
                yy += d[mp[pre]][0];
                xx += d[mp[pre]][1];
                if (yy >= n || yy < 0 || xx >= n || xx < 0)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
                if (mat[yy][xx] == 1)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
            }
        }
        if (q[i] == 'A')
        {
            if (event[1] == 0)
            {
                if (pre != q[i])
                {
                    yy += d[1][0];
                    xx += d[1][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[1][0];
                        xx -= d[1][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[1][0];
                        xx -= d[1][1];
                    }
                }
            }
            else if (event[1] == 1)
            {
                if (pre == q[i])
                {
                    yy += d[1][0];
                    xx += d[1][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[1][0];
                        xx -= d[1][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[1][0];
                        xx -= d[1][1];
                    }
                }
            }
        }
        if (pre == 'A')
        {
            if (event[mp[pre]] == 2 && mp[pre] != mp[q[i]])
            {
                yy += d[mp[pre]][0];
                xx += d[mp[pre]][1];
                if (yy >= n || yy < 0 || xx >= n || xx < 0)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
                if (mat[yy][xx] == 1)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
            }
        }
        if (q[i] == 'S')
        {
            if (event[2] == 0)
            {
                if (pre != q[i])
                {
                    yy += d[2][0];
                    xx += d[2][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[2][0];
                        xx -= d[2][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[2][0];
                        xx -= d[2][1];
                    }
                }
            }
            else if (event[2] == 1)
            {
                if (pre == q[i])
                {
                    yy += d[2][0];
                    xx += d[2][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[2][0];
                        xx -= d[2][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[2][0];
                        xx -= d[2][1];
                    }
                }
            }
        }
        if (pre == 'S')
        {
            if (event[mp[pre]] == 2 && mp[pre] != mp[q[i]])
            {
                yy += d[mp[pre]][0];
                xx += d[mp[pre]][1];
                if (yy >= n || yy < 0 || xx >= n || xx < 0)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
                if (mat[yy][xx] == 1)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
            }
        }
        if (q[i] == 'D')
        {
            if (event[3] == 0)
            {
                if (pre != q[i])
                {
                    yy += d[3][0];
                    xx += d[3][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[3][0];
                        xx -= d[3][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[3][0];
                        xx -= d[3][1];
                    }
                }
            }
            else if (event[3] == 1)
            {
                if (pre == q[i])
                {
                    yy += d[3][0];
                    xx += d[3][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    {
                        yy -= d[3][0];
                        xx -= d[3][1];
                    }
                    if (mat[yy][xx] == 1)
                    {
                        yy -= d[3][0];
                        xx -= d[3][1];
                    }
                }
            }
        }
        if (pre == 'D')
        {
            if (event[mp[pre]] == 2 && mp[pre] != mp[q[i]])
            {
                yy += d[mp[pre]][0];
                xx += d[mp[pre]][1];
                if (yy >= n || yy < 0 || xx >= n || xx < 0)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
                if (mat[yy][xx] == 1)
                {
                    yy -= d[mp[pre]][0];
                    xx -= d[mp[pre]][1];
                }
            }
        }

        pre = q[i];
        y = yy, x = xx;
        // cout << y + 1 << ' ' << x + 1 << '\n';
    }
    cout << y + 1 << ' ' << x + 1;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
            {
                sy = i;
                sx = j;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        if (s == "Down")
            event[i] = 0;
        else if (s == "Stay")
            event[i] = 1;
        else if (s == "Up")
            event[i] = 2;
    }
    cin >> q;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}