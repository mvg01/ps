#include <bits/stdc++.h>
using namespace std;

int n, m, sy, sx;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int htime[101];
int other[101][101];
vector<vector<char>> mat;
vector<pair<int, int>> ex, pep; // 출구와 사람 배열

void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({sy, sx, 0});
    bool **vis = new bool *[n];
    for (int i = 0; i < n; ++i)
    {
        vis[i] = new bool[m];
        fill(vis[i], vis[i] + m, false);
    }
    vis[sy][sx] = 1;
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        for (int i = 0; i < ex.size(); i++)
        {
            if (ex[i].first == y && ex[i].second == x)
            {
                htime[i] = t;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis[yy][xx])
                continue;
            if (mat[yy][xx] != 'X')
            {
                q.push({yy, xx, t + 1});
                vis[yy][xx] = 1;
            }
        }
    }
}

void bfs2(int idx)
{
    queue<tuple<int, int, int>> q;
    q.push({pep[idx].first, pep[idx].second, 0});
    bool **vis = new bool *[n];
    for (int i = 0; i < n; ++i)
    {
        vis[i] = new bool[m];
        fill(vis[i], vis[i] + m, false);
    }
    vis[pep[idx].first][pep[idx].second] = 1;
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        for (int i = 0; i < ex.size(); i++)
        {
            if (ex[i].first == y && ex[i].second == x)
            {
                other[idx][i] = t;
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis[yy][xx])
                continue;
            if (mat[yy][xx] != 'X')
            {
                q.push({yy, xx, t + 1});
                vis[yy][xx] = 1;
            }
        }
    }
}

void solve()
{
    bfs();
    for (int i = 0; i < pep.size(); i++)
    {
        for (int j = 0; j < 101; j++)
            other[i][j] = 1e9;
        bfs2(i);
    }
    int ans = 0;
    for (int i = 0; i < ex.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < pep.size(); j++)
        {
            if (htime[i] >= other[j][i])
                cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char> v;
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            v.push_back(s[j]);
            if (s[j] == 'H')
            {
                sy = i;
                sx = j;
            }
            else if (s[j] == '#')
                ex.push_back({i, j});
            else if (s[j] == 'P')
                pep.push_back({i, j});
        }
        mat.push_back(v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}