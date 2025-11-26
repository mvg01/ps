#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans;
char mat[31][31];
vector<pair<int, int>> S, M, R;
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int bfs(int sy, int sx, int ey, int ex, bool chk)
{
    int vis[31][31] = {
        0,
    };
    queue<pair<int, int>> q;
    q.push({sy, sx});
    vis[sy][sx] = 1;
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == ey && x == ex)
        {
            return vis[y][x] - 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis[yy][xx])
                continue;
            if (mat[yy][xx] == 'X')
                continue;
            if (!chk)
            {
                if (mat[yy][xx] == 'R')
                    continue;
            }
            q.push({yy, xx});
            vis[yy][xx] = vis[y][x] + 1;
        }
    }
    return 1e6;
}

int start()
{
    int cnt = 1e6;
    for (int i = 0; i < M.size(); i++)
    {
        int start = 0;
        for (int j = 0; j < S.size(); j++)
        {
            start += bfs(S[j].first, S[j].second, M[i].first, M[i].second, 0);
        }
        for (int j = 0; j < R.size(); j++)
        {
            int end = 0;
            int m = bfs(M[i].first, M[i].second, R[j].first, R[j].second, 1);
            for (int k = 0; k < S.size(); k++)
            {
                end += bfs(R[j].first, R[j].second, S[k].first, S[k].second, 0);
            }
            cnt = min(start + (int)(m * S.size()) + end, cnt);
        }
    }
    return cnt;
}

void solve(int c)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'S')
                S.push_back({i, j});
            if (mat[i][j] == 'M')
                M.push_back({i, j});
            if (mat[i][j] == 'R')
                R.push_back({i, j});
        }
    }
    ans = min(ans, start());
    cout << "Data Set " << c << ":\n";
    if (ans == 1e6)
        cout << "Impossible\n";
    else
        cout << ans << '\n';
}

void input()
{
    cin >> t;
    int c = 1;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> mat[i];
        ans = 1e6;
        S.clear();
        M.clear();
        R.clear();
        solve(c++);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}