#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[3001][3001];
vector<tuple<int, int, int>> v;

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    vis[y][x] = 1;
    q.push({y, x});
    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        if (y == n - 1 && x == m - 1)
        {
            cout << "YES\n"
                 << vis[y][x] - 1;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (!vis[yy][xx])
            {
                q.push({yy, xx});
                vis[yy][xx] = vis[y][x] + 1;
            }
        }
    }
    cout << "NO";
}

void f()
{
    for (auto i : v)
    {
        int y = get<0>(i);
        y--;
        int x = get<1>(i);
        x--;
        int p = get<2>(i);
        for (int i = 0; i < 4; i++)
        {
            if (i == 0 || i == 1)
            {
                for (int j = 0; j <= p; j++)
                {
                    int yy = y + j;
                    int xx = x + (p - j) * d[i][1];
                    if (yy >= n || yy < 0 || xx >= m || xx < 0)
                        continue;
                    vis[yy][xx] = 1;
                }
            }
            else if (i == 2)
            {
                for (int j = 0; j <= p; j++)
                {
                    int yy = y - (p - j) * d[i][0];
                    int xx = x - j;
                    if (yy >= n || yy < 0 || xx >= m || xx < 0)
                        continue;
                    vis[yy][xx] = 1;
                }
            }
            else if (i == 3)
            {
                for (int j = 0; j <= p; j++)
                {
                    int yy = y + (p - j) * d[i][0];
                    int xx = x + j;
                    if (yy >= n || yy < 0 || xx >= m || xx < 0)
                        continue;
                    vis[yy][xx] = 1;
                }
            }
        }
    }
}

void solve()
{
    f();
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << vis[i][j] << ' ';
        cout << '\n';
    }
    */
    bfs(0, 0);
}

void input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int y, x, p;
        cin >> y >> x >> p;
        v.push_back({y, x, p});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}