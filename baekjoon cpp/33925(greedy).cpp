#include <bits/stdc++.h>
using namespace std;

int n, j, s, h, k;
char m[3][101];
void solve()
{
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[0][i] == 'v')
        {
            if (s == 0)
                h -= k;
            else
                s--;
        }
        else if (m[1][i] == '^')
            a++;
        else if (m[2][i] == '^')
            b++;
    }
    for (int i = 0; i < b; i++)
    {
        if (j == 0)
            h -= k;
        else
            j--;
    }
    for (int i = 0; i < a; i++)
    {
        if (j <= 1)
            h -= k;
        else
            j -= 2;
    }
    if (h <= 0)
        h = -1;
    cout << h;
}

void input()
{
    cin >> n >> j >> s >> h >> k;
    for (int i = 0; i < 3; i++)
        cin >> m[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}