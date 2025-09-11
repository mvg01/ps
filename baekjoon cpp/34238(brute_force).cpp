#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
char s[101][101];
string c = "OX";
int d[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void find(int y, int x)
{
    for (int k = 0; k < 8; k++)
    {
        int ty = y, tx = x;
        int cnt = 0;
        for (int i = 0; i < 2; i++)
        {
            int yy = ty + d[k][0];
            int xx = tx + d[k][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                break;
            if (s[yy][xx] == c[i])
                cnt++;
            ty = yy;
            tx = xx;
        }
        if (cnt == 2)
            ans++;
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'F')
            {
                find(i, j);
            }
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}