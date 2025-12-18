#include <bits/stdc++.h>
using namespace std;

int n, ans;
int d[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
char mat[501][501];
pair<int, int> p;

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == '.')
            {
                int cnt = 0;
                for (int k = 0; k < 8; k++)
                {
                    int temp = 0;
                    int y = i;
                    int x = j;
                    while (1)
                    {
                        int yy = y + d[k][0];
                        int xx = x + d[k][1];
                        if (yy >= n || yy < 0 || xx >= n || xx < 0)
                            break;
                        if (mat[yy][xx] == 'W')
                            temp++;
                        else if (mat[yy][xx] == 'B')
                        {
                            cnt += temp;
                            break;
                        }
                        else
                            break;
                        y = yy;
                        x = xx;
                    }
                }
                if (ans < cnt)
                {
                    ans = cnt;
                    p.first = i;
                    p.second = j;
                }
            }
        }
    }
    if (ans == 0)
        cout << "PASS";
    else
        cout << p.second << ' ' << p.first << '\n'
             << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}