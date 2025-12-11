#include <bits/stdc++.h>
using namespace std;

int n, m, a[1001][1001], b[1001][1001];

void solve()
{
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] != b[j][m - 1])
                cnt++;
        }
        cout << cnt << ' ';
    }
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
        sort(b[i], b[i] + m);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}