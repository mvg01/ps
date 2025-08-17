#include <bits/stdc++.h>
using namespace std;

int p, n, a[1001], mat[101];

void solve()
{
    int turn = 1;
    for (int i = 0; i < n; i++, turn = 3 - turn)
    {
        int t = a[i];
        mat[t] = turn;
        int l = t - 1;
        while (l >= 1 && mat[l] == 3 - turn)
            l--;
        if (l >= 1 && mat[l] == turn)
        {
            for (int j = l + 1; j < t; j++)
                mat[j] = 0;
        }
        int r = t + 1;
        while (r <= p && mat[r] == 3 - turn)
            r++;
        if (r <= p && mat[r] == turn)
        {
            for (int j = t + 1; j < r; j++)
                mat[j] = 0;
        }
    }
    int x = 0, y = 0;
    for (int i = 1; i <= p; i++)
    {
        if (mat[i] == 1)
            x++;
        else if (mat[i] == 2)
            y++;
    }
    cout << x << ' ' << y;
}

void input()
{
    cin >> p >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}