#include <bits/stdc++.h>
using namespace std;

int t, n, a[4];
int d[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
char mat[4][4];

int solve()
{
    bool vis[4][4] = {
        0,
    };
    vis[1][1] = 1;
    int idx = 0;
    vector<int> temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                int cnt = 1;
                while (q.size())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int yy = y + d[k][0];
                        int xx = x + d[k][1];
                        if (yy >= 3 || yy < 0 || xx >= 3 || xx < 0)
                            continue;
                        if (vis[yy][xx])
                            continue;
                        if (mat[yy][xx] == 'O')
                        {
                            cnt++;
                            q.push({yy, xx});
                            vis[yy][xx] = 1;
                        }
                    }
                }
                temp.push_back(cnt);
            }
        }
    }
    if (n == 0)
    {
        if (temp.empty())
            return 1;
        else
            return 0;
    }
    sort(temp.begin(), temp.end());
    if (temp.size() != n)
        return 0;
    while (idx != n)
    {
        if (temp[idx] != a[idx])
            return 0;
        idx++;
    }
    return 1;
}

void input()
{
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
            cin >> mat[i];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve() << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}