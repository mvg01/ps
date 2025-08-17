#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char mat[1001][1001];
bool vis[11][1001][1001];
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve()
{
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 1});
    vis[0][0][0] = 1;
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int brk = get<2>(q.front());
        int day = get<3>(q.front());
        q.pop();
        if (y == n - 1 && x == m - 1)
        {
            cout << day;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (mat[yy][xx] == '1' && brk < k)
            {
                if (day % 2 == 1)
                {
                    if (!vis[brk + 1][yy][xx])
                    {
                        vis[brk + 1][yy][xx] = 1;
                        q.push({yy, xx, brk + 1, day + 1});
                    }
                }
                else
                {
                    q.push({y, x, brk, day + 1});
                }
            }
            else if (mat[yy][xx] == '0' && !vis[brk][yy][xx])
            {
                vis[brk][yy][xx] = 1;
                q.push({yy, xx, brk, day + 1});
            }
        }
    }
    cout << -1;
}

void input()
{
    cin >> n >> m >> k;
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