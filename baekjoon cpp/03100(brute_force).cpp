#include <bits/stdc++.h>
using namespace std;

char mat[7][10];
int a[3][26], b[3][26];
int temp[3];
int r, c;

void solve()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 9; j++)
            a[0][mat[i][j] - 'A']++;
    }
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 9; j++)
            a[1][mat[i][j] - 'A']++;
    }
    for (int i = 4; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
            a[2][mat[i][j] - 'A']++;
    }
    for (int i = 0; i < 3; i++)
    {
        int mx = 0;
        if (i == 1)
            continue;
        for (int j = 0; j < 26; j++)
        {
            if (mx < a[i][j])
            {
                mx = a[i][j];
                temp[i] = j;
            }
        }
        r += 18 - mx;
    }
    int mx = 0;
    for (int j = 0; j < 26; j++)
    {
        if (mx < a[1][j])
        {
            if (temp[0] == j || temp[2] == j)
                continue;
            mx = a[1][j];
        }
    }
    r += 18 - mx;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
            b[0][mat[j][i] - 'A']++;
    }
    for (int i = 3; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            b[1][mat[j][i] - 'A']++;
    }
    for (int i = 6; i < 9; i++)
    {
        for (int j = 0; j < 6; j++)
            b[2][mat[j][i] - 'A']++;
    }
    for (int i = 0; i < 3; i++)
    {
        int mx = 0;
        if (i == 1)
            continue;
        for (int j = 0; j < 26; j++)
        {
            if (mx < b[i][j])
            {
                mx = b[i][j];
                temp[i] = j;
            }
        }
        c += 18 - mx;
    }
    mx = 0;
    for (int j = 0; j < 26; j++)
    {
        if (mx < b[1][j])
        {
            if (temp[0] == j || temp[2] == j)
                continue;
            mx = b[1][j];
        }
    }
    c += 18 - mx;
    cout << min(r, c);
}

void input()
{
    for (int i = 0; i < 6; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}